#include "../includes/winpack.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    FILE *fp = fopen("test.exe", "rb");
    size_t file_size = 0;
    file_memory_t fm;

    if (!fp)
        return (1);

    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *ptr_data = (char *)malloc((sizeof(char) * file_size) + 1);

    if (fread(ptr_data, sizeof(char), file_size, fp) != file_size) {
        free(ptr_data);
        return (1);
    }

    fclose(fp);

    void *op = LoadPE(ptr_data, &fm);

    if (op) {
        ((void (*)(void)) op)();
    }
    
    free_file_memory(&fm);

    return (0);
}