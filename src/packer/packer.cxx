#include "winpack.h"
#include "winpack.hpp"
#include <fstream>
#include <LIEF/LIEF.hpp>

using namespace std;

vector<unsigned char> Packer::read_file(string filename)
{
    ifstream istream;
    vector<unsigned char> byte_array;
    unsigned char byte = 0;

    istream.open(filename, ios::binary);

    if (!istream.is_open())
        return (byte_array);
    
    istream.unsetf(ios::skipws);
    
    while (!istream.eof()) {
        istream >> byte;
        byte_array.push_back(byte);
    }

    istream.close();

    return (byte_array);
}

uint8_t Packer::pack_binary(string packed_file, string stub_filename, string output_filename, unsigned char key)
{
    try {
        unique_ptr<LIEF::PE::Binary> stub_file = LIEF::PE::Parser::parse(stub_filename);
        vector<unsigned char>byte_array;
        LIEF::PE::Section new_section;

        byte_array = read_file(packed_file);

        xor_buffer(byte_array.data(), key, byte_array.size());

        new_section.content(byte_array);
        new_section.add_characteristic(LIEF::PE::SECTION_CHARACTERISTICS::IMAGE_SCN_MEM_READ | LIEF::PE::SECTION_CHARACTERISTICS::IMAGE_SCN_MEM_WRITE | LIEF::PE::SECTION_CHARACTERISTICS::IMAGE_SCN_CNT_INITIALIZED_DATA);
        new_section.size(byte_array.size());

        stub_file->add_section(new_section);

        stub_file->optional_header().sizeof_image(0);

        LIEF::PE::Builder builder{stub_file.get()};

        builder.build();
        builder.write(output_filename);

        cout << "[+] " << packed_file << " is packed in " << output_filename << " ! " << endl;


    } catch (LIEF::exception &err) {
        cout << "Error : " << err.what() << endl;
        return (1);
    }

    return (0);
}