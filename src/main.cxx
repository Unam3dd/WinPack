#include "../includes/winpack.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 5) {
        cout << "eror not enough args !" << endl;
        return (1);
    }

    if (Packer::pack_binary(argv[1], argv[2], argv[3], argv[4][0]))
        return (1);
    
    return (0);
}