#include "../../includes/winpack.h"
#include <stdlib.h>

void free_file_memory(file_memory_t *fm)
{
    if (fm->ImageBase)
        VirtualFree(fm->ImageBase, 0, MEM_RELEASE);
    
    if (fm->ptr_data)
        free(fm->ptr_data);
}