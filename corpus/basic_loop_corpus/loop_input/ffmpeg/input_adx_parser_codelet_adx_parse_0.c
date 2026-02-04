#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct ADXParseContext {
    ParseContext pc;
    int header_size;
    int block_size;
    int remaining;
} ADXParseContext;

uint8_t *buf;
int buf_size;
ADXParseContext *s;
int i;
uint64_t state;

void init_vars() {
    // Allocate a large buffer to make loop run about 0.01 seconds
    // Assume ~1GB/s processing speed -> need ~10MB for 0.01s
    buf_size = 16777216; // 16MB
    buf = (uint8_t*)malloc(buf_size);
    if (!buf) {
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }

    // Initialize buffer with random data
    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }

    // Place valid pattern near the end to ensure detection within bounds
    // Pattern: state == 9223372036906288128ULL | channels | (header_size << 32)
    // We want: (state & 18446462603027808000UL) == 9223372036906288128ULL
    // So highest 16 bits must be 0x7FF0
    // Let's place the pattern at position allowing full read
    int pos = buf_size - 1000;
    uint64_t target_state = 9223372036906288128ULL; // 0x7FF0000000000000
    target_state |= 2; // channels = 2
    target_state |= ((uint64_t)(16)) << 32; // header_size_base = 16, so total header_size = 20

    // Write the 8-byte sequence that will form this state
    for (int j = 0; j < 8; j++) {
        buf[pos + j] = (target_state >> (56 - j * 8)) & 0xFF;
    }

    s = (ADXParseContext*)calloc(1, sizeof(ADXParseContext));
    if (!s) {
        fprintf(stderr, "Calloc failed\n");
        exit(1);
    }

    state = 0;
    i = 0;
}