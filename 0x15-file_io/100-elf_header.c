#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ELF_MAGIC "\x7f\x45\x4c\x46"

struct elf_header {
unsigned char magic[4];
unsigned char class;
unsigned char data;
unsigned char version;
unsigned char abi;
unsigned char abi_version;
char pad[7];
uint16_t type;
uint16_t machine;
uint32_t version2;
uint64_t entry;
uint64_t phoff;
uint64_t shoff;
uint32_t flags;
uint16_t ehsize;
uint16_t phentsize;
uint16_t phnum;
uint16_t shentsize;
uint16_t shnum;
uint16_t shstrndx;
};

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return 1;
}

int fd = open(argv[1], O_RDONLY);
if (fd == -1) {
fprintf(stderr, "Error opening file: %s\n", strerror(errno));
return 98;
}

struct elf_header header;
ssize_t n = read(fd, &header, sizeof(header));
if (n == -1) {
fprintf(stderr, "Error reading file: %s\n", strerror(errno));
close(fd);
return 98;
}

if (memcmp(header.magic, ELF_MAGIC, sizeof(ELF_MAGIC) - 1) != 0) {
fprintf(stderr, "File is not an ELF file\n");
close(fd);
return 98;
}

printf("Magic: %02x %02x %02x %02x\n",
header.magic[0], header.magic[1], header.magic[2], header.magic[3]);

printf("Class: %s\n", header.class == 1 ? "ELF32" : "ELF64");

printf("Data: %s\n", header.data == 1 ? "little endian" : "big endian");

printf("Version: %d\n", header.version);

printf("OS/ABI: ");
switch (header.abi) {
case 0: printf("System V ABI\n"); break;
case 3: printf("Linux ABI\n"); break;
default: printf("Unknown ABI (%d)\n", header.abi); break;
}

printf("ABI Version: %d\n", header.abi_version);

printf("Type: ");
switch (header.type) {
case 1: printf("Relocatable file\n"); break;
case 2: printf("Executable file\n"); break;
case 3: printf("Shared object file\n"); break;
case 4: printf("Core file\n"); break;
default: printf("Unknown type (%d)\n", header.type); break;
}

printf("Entry point address: 0x%lx\n", header.entry);

printf("Format: %s\n", header.class


