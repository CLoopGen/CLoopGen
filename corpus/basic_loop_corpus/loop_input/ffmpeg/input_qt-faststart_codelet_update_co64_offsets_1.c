#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    uint64_t moov_atom_size;
    uint64_t stco_offset_count;
    uint64_t stco_data_size;
    int stco_overflow;
    uint32_t depth;
} update_chunk_offsets_context_t;

typedef struct {
    uint32_t type;
    uint32_t header_size;
    uint64_t size;
    unsigned char *data;
} atom_t;

update_chunk_offsets_context_t *context;
atom_t *atom;
uint64_t current_offset;
uint32_t offset_count;
unsigned char *pos;
unsigned char *end;

static unsigned char *buffer;
static uint32_t allocated_offset_count;

void init_vars() {
    allocated_offset_count = 16777216; // ~128MB of data (16M * 8 bytes)
    buffer = (unsigned char *)calloc(allocated_offset_count * 8 + 8, sizeof(unsigned char));
    if (!buffer) exit(1);

    context = (update_chunk_offsets_context_t *)calloc(1, sizeof(update_chunk_offsets_context_t));
    if (!context) exit(1);
    context->moov_atom_size = 0x10000000ULL;
    context->stco_offset_count = allocated_offset_count;
    context->depth = 1;

    atom = (atom_t *)calloc(1, sizeof(atom_t));
    if (!atom) exit(1);
    atom->type = 0x7374636f; // 'stco'
    atom->header_size = 8;
    atom->size = allocated_offset_count * 8 + 8;
    atom->data = buffer;

    for (uint32_t i = 0; i < allocated_offset_count; ++i) {
        uint64_t val = 0xABCDEF0000000000ULL + i * 0x12345678ULL;
        buffer[8 + i*8 + 0] = (val >> 56) & 0xFF;
        buffer[8 + i*8 + 1] = (val >> 48) & 0xFF;
        buffer[8 + i*8 + 2] = (val >> 40) & 0xFF;
        buffer[8 + i*8 + 3] = (val >> 32) & 0xFF;
        buffer[8 + i*8 + 4] = (val >> 24) & 0xFF;
        buffer[8 + i*8 + 5] = (val >> 16) & 0xFF;
        buffer[8 + i*8 + 6] = (val >> 8) & 0xFF;
        buffer[8 + i*8 + 7] = val & 0xFF;
    }

    offset_count = allocated_offset_count;
    pos = NULL;
    end = NULL;
    current_offset = 0;
}