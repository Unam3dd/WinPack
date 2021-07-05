#include "../../includes/winpack.h"
#include <stdlib.h>

void free_file_memory(file_memory_t *fm)
{
    if (fm->ImageBase)
        VirtualFree(fm->ImageBase, 0, MEM_RELEASE);
    
    if (fm->ptr_data)
        free(fm->ptr_data);
}

void *memory_copy(void *dst, const void *src, size_t size)
{
    char *ptr_dst = (char *)dst;
    char *ptr_src = (char *)src;

    while (size--)
        *ptr_dst++ = *ptr_src++;
    
    return (dst);
}

void *memory_set(void *dst, char c, size_t size)
{
    char *ptr_dst = (char *)dst;

    while (size--)
        *ptr_dst = c;
    
    return (dst);
}