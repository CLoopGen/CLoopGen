#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ArgoASFFileHeader {
    uint32_t magic;
    uint16_t version_major;
    uint16_t version_minor;
    uint32_t num_chunks;
    uint32_t chunk_offset;
    int8_t name[8];
} ArgoASFFileHeader;

ArgoASFFileHeader *hdr;
uint8_t *buf;

void init_vars() {
    // Allocate buffer large enough to support access at offset 16 + up to 7 (since name is 8 bytes)
    buf = (uint8_t*)calloc(24, sizeof(uint8_t));
    if (!buf) exit(1);

    hdr = (ArgoASFFileHeader*)malloc(sizeof(ArgoASFFileHeader));
    if (!hdr) exit(1);

    // Ensure the part of buf we're reading from (16 to 23) is initialized
    for (int i = 0; i < 8; i++) {
        buf[16 + i] = (uint8_t)(i + 1);
    }

    // Initialize other fields of hdr to avoid undefined behavior when accessed
    hdr->magic = 0x12345678;
    hdr->version_major = 1;
    hdr->version_minor = 0;
    hdr->num_chunks = 0;
    hdr->chunk_offset = 0;
    // name field will be overwritten by the loop, so no need to initialize
}