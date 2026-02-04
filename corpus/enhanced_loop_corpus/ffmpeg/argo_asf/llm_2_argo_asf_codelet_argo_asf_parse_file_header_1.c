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

extern ArgoASFFileHeader *hdr;
extern  uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src = (uint8_t *)(buf + 16);
    int8_t *dst = hdr->name;
    for (int i = 0; i < (sizeof(hdr->name) / sizeof(hdr->name[0])); i++) {
        dst[i] = src[i];
    }
}
