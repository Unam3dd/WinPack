#pragma once
#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <windows.h>


// utils.c
typedef struct file_memory_t file_memory_t;

struct file_memory_t
{
    char *ptr_data;
    char *ImageBase;
};

void free_file_memory(file_memory_t *fm);
void *memory_copy(void *dst, const void *src, size_t size);
void *memory_set(void *dst, char c, size_t size);



// reader.c
char *read_file(const char *filename);

// loader.c
uint8_t check_file_format(WORD dos_sign, DWORD nt_sign);
void write_sections(char *ImageBase, char *ptr_data, PIMAGE_SECTION_HEADER sections, WORD nsections);
void write_imports(char *ImageBase, PIMAGE_IMPORT_DESCRIPTOR import_descriptor);
void write_relocations(char *ImageBase, PIMAGE_BASE_RELOCATION base_reloc, DWORD delta);
void write_protections(char *ImageBase, PIMAGE_SECTION_HEADER sections, WORD nsections, DWORD size_of_headers);
void *LoadPE(char *ptr_data, file_memory_t *fm);