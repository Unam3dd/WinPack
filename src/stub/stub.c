#include "../../includes/winpack.h"
#include <stdio.h>

// cl /TC src\stub\stub.c src\loader\loader.c src\cipher\cipher.c /link /MACHINE:x86 /OUT:stub.exe

int main(void)
{
    char *binary = NULL, *addr = NULL;
    
    binary = (char *)GetModuleHandleA(NULL);

    PIMAGE_DOS_HEADER dos_hdr = (PIMAGE_DOS_HEADER) binary;
    PIMAGE_NT_HEADERS nt_hdrs = (PIMAGE_NT_HEADERS) (((char *) dos_hdr) + dos_hdr->e_lfanew);
    PIMAGE_SECTION_HEADER sections_hdr = (PIMAGE_SECTION_HEADER) (nt_hdrs + 0x1);

    addr = (binary + sections_hdr[nt_hdrs->FileHeader.NumberOfSections - 1].VirtualAddress);

    xor_buffer(addr, 'z', sections_hdr[nt_hdrs->FileHeader.NumberOfSections - 1].SizeOfRawData);

    void (*ep)(void) = (void (*)(void)) LoadPE(addr);

    if (!ep)
        return (1);
    
    ep();

    return (0);
}