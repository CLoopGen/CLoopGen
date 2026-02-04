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
    for (int i = 0; i < (sizeof(hdr->name) / sizeof((hdr->name)[0])); i += 2) {
        hdr->name[i] = ((const uint8_t*)(buf + 16 + i))[0];
        if (i + 1 < (sizeof(hdr->name) / sizeof((hdr->name)[0]))) {
            hdr->name[i + 1] = ((const uint8_t*)(buf + 16 + i + 1))[0];
        }
    }
}
