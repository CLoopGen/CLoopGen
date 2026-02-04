#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DiracParseContext {
    int state;
    int is_synced;
    int sync_offset;
    int header_bytes_needed;
    int overread_index;
    int buffer_size;
    int index;
    uint8_t *buffer;
    int dirac_unit_size;
    uint8_t *dirac_unit;
} DiracParseContext;

DiracParseContext *pc;
uint8_t *buf;
int buf_size;
uint32_t state;
int i;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime on modern CPU
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        exit(1);
    }

    // Initialize buffer with non-matching pattern until near the end
    for (int j = 0; j < buf_size - 4; j++) {
        buf[j] = (uint8_t)(j & 0xFF);
    }

    // Insert target state value 1111638852 (0x42424244) at the end to trigger match
    buf[buf_size - 4] = 0x42;
    buf[buf_size - 3] = 0x42;
    buf[buf_size - 2] = 0x42;
    buf[buf_size - 1] = 0x44;

    pc = (DiracParseContext *)malloc(sizeof(DiracParseContext));
    if (!pc) {
        exit(1);
    }

    pc->state = 0;
    pc->is_synced = 0;
    pc->sync_offset = 0;
    pc->header_bytes_needed = 0;
    pc->overread_index = 0;
    pc->buffer_size = 0;
    pc->index = 0;
    pc->buffer = NULL;
    pc->dirac_unit_size = 0;
    pc->dirac_unit = NULL;

    state = 0; // Initial shift state
    i = 0;
}