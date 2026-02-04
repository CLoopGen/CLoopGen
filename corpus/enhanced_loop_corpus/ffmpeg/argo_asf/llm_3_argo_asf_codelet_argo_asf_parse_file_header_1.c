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
    // Variant 2: Strided memory access (stride of 1, but accessed in reverse order - backward traversal)
    int len = sizeof(hdr->name) / sizeof(hdr->name[0]);
    for (int i = len - 1; i >= 0; i--) {
        hdr->name[i] = ((const uint8_t *)(buf + 16))[i];
    }
}
