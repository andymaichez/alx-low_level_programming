#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFFER_SIZE 1024

/**
 * print_error - prints the error of a message
 * print_elf_header - prints the header information of
 * an elf header file
 */
void print_error(const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
exit(98);
}

void print_elf_header(const Elf64_Ehdr *elf_header)
{
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", elf_header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n",
elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
elf_header->e_ident[EI_CLASS] == ELFCLASSNONE ? "Invalid class" : "Unknown");
printf("  Data:                              %s\n",
elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
elf_header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
elf_header->e_ident[EI_DATA] == ELFDATANONE ? "Invalid data encoding" : "Unknown");
printf("  Version:                           %d (%s)\n",
elf_header->e_ident[EI_VERSION],
elf_header->e_ident[EI_VERSION] == EV_CURRENT ? "current" :
elf_header->e_ident[EI_VERSION] == EV_NONE ? "invalid version" : "unknown");
printf("  OS/ABI:                            %s\n",
elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "Solaris ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_AIX ? "AIX ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "FreeBSD ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "OpenBSD ABI" :
elf_header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone (embedded) ABI" : "Unknown");
printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
printf("  Type:                              %s\n",
elf_header->e_type == ET_NONE ? "NONE (No file type)" :
elf_header->e_type == ET_REL ? "REL (Relocatable file)" :
elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" :
elf_header->e_type == ET_DYN ? "DYN (Shared object file)" :
elf_header->e_type

