#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

typedef struct PNGParseContext {
    ParseContext pc;
    uint32_t chunk_pos;
    uint32_t chunk_length;
    uint32_t remaining_size;
} PNGParseContext;

uint8_t *buf;
int buf_size;
PNGParseContext *ppc;
int i;
uint64_t state64;

void init_vars() {
    // Allocate 64MB of input data to target ~0.01 seconds runtime on modern CPUs
    buf_size = 64 * 1024 * 1024;
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random data, but ensure the pattern appears near the end
    // to avoid early loop termination and ensure full traversal
    memset(buf, 0, buf_size);
    
    // Fill most of the buffer with non-matching data
    for (int j = 0; j < buf_size - 8; j++) {
        buf[j] = (uint8_t)(j % 251); // Prime number pattern to reduce accidental matches
    }
    
    // Place one of the target patterns at the very end to trigger match near loop exit
    uint64_t target = 9894494448401390090UL; // One of the two magic values
    for (int j = 0; j < 8; j++) {
        buf[buf_size - 8 + j] = (target >> (56 - j * 8)) & 0xFF;
    }

    // Allocate and initialize PNGParseContext
    ppc = (PNGParseContext *)calloc(1, sizeof(PNGParseContext));
    if (!ppc) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize parser context fields
    ppc->pc.buffer = buf;
    ppc->pc.buffer_size = buf_size;
    ppc->pc.frame_start_found = 0;
    ppc->chunk_pos = 0;
    ppc->chunk_length = 0;
    ppc->remaining_size = 0;

    // Initialize loop index and state
    i = 0;
    state64 = 0;
}