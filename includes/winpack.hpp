#pragma once
#include <iostream>
#include <vector>


// packer.cxx

namespace Packer
{
    std::vector<unsigned char> read_file(std::string filename);
    uint8_t pack_binary(std::string packed_file, std::string stub_filename, std::string output_filename, unsigned char key);
}