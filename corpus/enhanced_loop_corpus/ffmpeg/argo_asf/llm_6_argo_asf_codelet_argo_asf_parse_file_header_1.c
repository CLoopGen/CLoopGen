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



void loop() {
    int size = sizeof(hdr->name) / sizeof((hdr->name)[0]);
    uint8_t temp[8];
    for (int i = 0; i < size; i++) {
        temp[i] = ((const uint8_t*)(buf + 16))[i];
    }
    for (int i = 0; i < size; i++) {
        hdr->name[i] = temp[i];
    }
}
