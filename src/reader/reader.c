#include "../../includes/winpack.h"

//////////////////////////////////////////////
//
//          READER
//
/////////////////////////////////////////////

#include <stdio.h>

char *read_file(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    size_t file_size = 0;

    if (!fp)
        return (NULL);
    
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    char *ptr_data = (char *)malloc((sizeof(char) * file_size) + 0x1);

    if (fread(ptr_data, sizeof(char), file_size, fp) != file_size) {
        free(ptr_data);
        return (NULL);
    }

    return (ptr_data);
}