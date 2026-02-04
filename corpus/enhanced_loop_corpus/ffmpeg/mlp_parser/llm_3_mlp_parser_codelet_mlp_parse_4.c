#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ParseContext {
    uint8_t *buffer;
    int index;
    int last_index;
    unsigned int buffer_size;
    uint32_t state;
    int frame_start_found;
    int overread;
    int overread_index;
    uint64_t state64;
} ParseContext;

typedef struct MLPParseContext {
    ParseContext pc;
    int bytes_left;
    int in_sync;
    int num_substreams;
} MLPParseContext;

extern  uint8_t *buf;
extern MLPParseContext *mp;
extern uint8_t parity_bits;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern with fixed stride to simulate non-sequential layout
    uint8_t *b = buf;
    int stride = 4; // Simulate strided data layout
    parity_bits = 0;
    int n = mp->num_substreams + 1; // Include i = -1 as first iteration

    for (i = 0; i < n; i++) {
        int base = i * stride;
        parity_bits ^= b[p + base + 0];
        parity_bits ^= b[p + base + 1];
        
        // Every substream now conditionally accesses next two based on high bit of second byte
        if (i == 0 || (b[p + base + 1] & 128)) {
            parity_bits ^= b[p + base + 2];
            parity_bits ^= b[p + base + 3];
            p += 4;
        } else {
            p += 2;
        }
    }
}
