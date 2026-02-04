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
    // Variant 1: Consecutive memory access with pointer arithmetic and unrolling
    uint8_t *b = buf;
    parity_bits = 0; // Reset for deterministic behavior
    int n = mp->num_substreams;
    
    // Process main substreams with direct consecutive access
    for (i = 0; i < n; i++) {
        parity_bits ^= b[p++];
        parity_bits ^= b[p++];
        parity_bits ^= b[p++];
        parity_bits ^= b[p++];
    }
    
    // Handle initial special case (i = -1 equivalent) separately
    parity_bits ^= buf[0];
    parity_bits ^= buf[1];
    parity_bits ^= buf[2];
    parity_bits ^= buf[3];
}
