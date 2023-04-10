#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>

void print_magic(unsigned char *e_ident) {
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

void print_class(unsigned char e_ident[EI_NIDENT]) {
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
            break;
    }
}

void print_data(unsigned char e_ident[EI_NIDENT]) {
    printf("  Data:                              ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
            break;
    }
}

void print_version(unsigned char e_ident[EI_NIDENT]) {
    printf("  Version:                           %d", e_ident[EI_VERSION]);
    if (e_ident[EI_VERSION] == EV_CURRENT) {
        printf(" (current)\n");
    } else {
        printf(" <unknown>\n");
    }
}

void print_osabi(unsigned char e_ident[EI_NIDENT]) {
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("UNIX - AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell - Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("UNIX - OpenBSD\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
            break;
    }
}

void print_abi_version(unsigned char e_ident[EI_NIDENT]) {
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(Elf64_Half e_type) {
    printf("  Type:                              ");
    switch (e_type) {
        case ET_NONE:
            printf("NONE (None)\n");

