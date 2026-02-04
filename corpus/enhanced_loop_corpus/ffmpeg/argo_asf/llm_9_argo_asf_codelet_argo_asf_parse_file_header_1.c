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
    const int size = sizeof(hdr->name) / sizeof((hdr->name)[0]);
    uint32_t offset_base = 16;
    for (int i = 0; i < size; i++) {
        uint32_t addr = offset_base + i;
        uint8_t val = *(const uint8_t *)(buf + addr);
        hdr->name[i] = (int8_t)val;
    }
}
