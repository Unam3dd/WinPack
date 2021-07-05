#include "../includes/winpack.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    file_memory_t fm;

    char *ptr_data = read_file("test.exe");

    void *op = LoadPE(ptr_data, &fm);

    if (op)
        JUMP_PEOP(op);
    
    free_file_memory(&fm);

    return (0);
}