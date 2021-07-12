#pragma once
#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <windows.h>

//////////////////////////////////////////////////
//             DEFINE
/////////////////////////////////////////////////
//#define JUMP_PEOP(ep) ((void (*)(void)) ep)();

// loader.c
unsigned char check_file_format(WORD dos_sign, DWORD nt_sign);
void write_sections(char *ImageBase, char *ptr_data, PIMAGE_SECTION_HEADER sections, WORD nsections);
void write_imports(char *ImageBase, PIMAGE_IMPORT_DESCRIPTOR import_descriptor);
void write_relocations(char *ImageBase, PIMAGE_BASE_RELOCATION base_reloc, DWORD delta);
void write_protections(char *ImageBase, PIMAGE_SECTION_HEADER sections, WORD nsections, DWORD size_of_headers);
void *LoadPE(char *ptr_data);

// cipher.c
unsigned char *xor_buffer(unsigned char *buffer, unsigned char key, unsigned long long size_buffer);