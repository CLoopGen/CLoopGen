#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct PayloadContext {
    int block_type;
    int block_size;
    int subpkts_per_block;
    uint16_t len[128];
    uint8_t buf[128][2048];
    unsigned int cache;
    unsigned int n_pkts;
    uint32_t timestamp;
};


typedef struct PayloadContext PayloadContext;

extern PayloadContext *qdm;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (n = 127; n >= 0; n--)
        if (qdm->len[n] > 0)
            break;
}
