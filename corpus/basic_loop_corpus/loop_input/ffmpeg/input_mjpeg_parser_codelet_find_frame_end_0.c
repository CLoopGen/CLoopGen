#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

typedef struct MJPEGParserContext {
    ParseContext pc;
    int size;
} MJPEGParserContext;

MJPEGParserContext *m;
uint8_t *buf;
int buf_size;
int vop_found;
int i;
uint32_t state;

void init_vars() {
    buf_size = 16777216; // 16MB to target ~0.01s runtime on modern CPU
    buf = (uint8_t*)malloc(buf_size);
    
    if (!buf) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }

    // Initialize buffer with pseudo-random but deterministic data
    srand(12345);
    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }

    // Force some patterns that may trigger conditions in the loop
    // Insert a sequence that will match the vop_found condition after shifting
    // We want: state >= 4292411328U && state <= 4292411391U
    // That corresponds to 0xFFA08000 to 0xFFA0803F
    // So we can place bytes like 0xFF, 0xA0, 0x80, 0x00... at strategic location
    int trigger_pos = buf_size / 2;
    if (trigger_pos + 4 <= buf_size) {
        buf[trigger_pos] = 0xFF;
        buf[trigger_pos + 1] = 0xA0;
        buf[trigger_pos + 2] = 0x80;
        buf[trigger_pos + 3] = 0x01;
    }

    m = (MJPEGParserContext*)calloc(1, sizeof(MJPEGParserContext));
    if (!m) {
        fprintf(stderr, "Failed to allocate m context\n");
        exit(1);
    }

    m->pc.buffer = buf;
    m->pc.buffer_size = buf_size;
    m->pc.state = 0;
    m->size = 0;

    vop_found = 0;
    i = 0;
    state = 0;
}

// Ensure definitions are available externally
MJPEGParserContext *m;
uint8_t *buf;
int buf_size;
int vop_found;
int i;
uint32_t state;