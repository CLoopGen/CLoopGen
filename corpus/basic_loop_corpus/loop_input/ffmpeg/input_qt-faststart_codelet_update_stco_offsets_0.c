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
uint32_t current_offset;
uint32_t offset_count;
unsigned char *pos;
unsigned char *end;

static unsigned char *g_data_buffer;
static update_chunk_offsets_context_t g_context;
static atom_t g_atom;

void init_vars() {
    // Allocate approximately 16MB of data to target ~0.01s runtime
    size_t data_size = 16 * 1024 * 1024;
    g_data_buffer = (unsigned char *)calloc(1, data_size);
    if (!g_data_buffer) exit(1);

    // Set up atom with 8-byte header, rest is data
    g_atom.type = 0x7374636F; // 'stco'
    g_atom.header_size = 8;
    g_atom.size = data_size + 8;
    g_atom.data = g_data_buffer;

    // Initialize context
    g_context.moov_atom_size = 5000000;
    g_context.stco_offset_count = 0;
    g_context.stco_data_size = 0;
    g_context.stco_overflow = 0;
    g_context.depth = 1;

    // Set global pointers
    context = &g_context;
    atom = &g_atom;

    // Initialize data: write 10000 offsets (40KB), each 4 bytes
    offset_count = 10000;
    for (uint32_t i = 0; i < offset_count; i++) {
        uint32_t val = 100000 + (i * 100); // Increasing offsets
        g_data_buffer[8 + i*4 + 0] = (val >> 24) & 255;
        g_data_buffer[8 + i*4 + 1] = (val >> 16) & 255;
        g_data_buffer[8 + i*4 + 2] = (val >> 8)  & 255;
        g_data_buffer[8 + i*4 + 3] = val        & 255;
    }

    // Ensure pos and end are initialized by the loop itself
    // They are updated in the loop, so no need to set here
}