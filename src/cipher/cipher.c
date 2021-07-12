#include "../../includes/winpack.h"

unsigned char *xor_buffer(unsigned char *buffer, unsigned char key, unsigned long long size_buffer)
{
    unsigned char *tmp = buffer;

    while (size_buffer--)
        *tmp++ ^= key;
    
    return (buffer);
}