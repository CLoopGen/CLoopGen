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
    for (int i = 0; i < (sizeof (hdr->name) / sizeof ((hdr->name)[0])); i++) {
        for (int k = 0; k < 1; k++) {
            hdr->name[i] = (((const uint8_t *)(buf + 16 + i))[0]);
        }
    }
}
