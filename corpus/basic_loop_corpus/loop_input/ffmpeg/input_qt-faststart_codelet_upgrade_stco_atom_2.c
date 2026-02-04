#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct {
    unsigned char *dest;
    uint64_t original_moov_size;
    uint64_t new_moov_size;
} upgrade_stco_context_t;

typedef struct {
    uint32_t type;
    uint32_t header_size;
    uint64_t size;
    unsigned char *data;
} atom_t;

upgrade_stco_context_t *context;
atom_t *atom;
unsigned char *pos;
unsigned char *end;
uint64_t new_offset;
uint32_t offset_count;
uint32_t original_offset;

static unsigned char *global_data_buffer;
static unsigned char *global_dest_buffer;

void init_vars() {
    // Set up a data size that will take about 0.01 seconds to process
    // The loop processes offset_count * 4 bytes, each iteration doing 8-byte write
    // On modern CPUs, memory-bound loops like this can process ~1-10 GB/s
    // So for 0.01s, we want roughly 10-100 MB of output data -> aim for ~50M iterations

    offset_count = 12500000;  // 12.5M entries * 4 bytes = 50MB input, produces 100MB output (8 bytes per entry)

    size_t data_size = offset_count * 4;
    size_t dest_size = offset_count * 8;

    // Allocate buffers
    global_data_buffer = (unsigned char*)aligned_alloc(32, data_size);
    global_dest_buffer = (unsigned char*)aligned_alloc(32, dest_size);

    if (!global_data_buffer || !global_dest_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with predictable values
    for (uint32_t i = 0; i < offset_count; i++) {
        uint32_t val = 1000000 + i * 4;  // Starting offset base
        global_data_buffer[i*4 + 0] = (val >> 24) & 0xFF;
        global_data_buffer[i*4 + 1] = (val >> 16) & 0xFF;
        global_data_buffer[i*4 + 2] = (val >> 8) & 0xFF;
        global_data_buffer[i*4 + 3] = val & 0xFF;
    }

    // Allocate and initialize atom
    atom = (atom_t*)malloc(sizeof(atom_t));
    atom->type = 0x7374636F;  // 'stco'
    atom->header_size = 8;
    atom->size = data_size + 8;
    atom->data = global_data_buffer;

    // Allocate and initialize context
    context = (upgrade_stco_context_t*)malloc(sizeof(upgrade_stco_context_t));
    context->dest = global_dest_buffer;
    context->original_moov_size = 1000000;
    context->new_moov_size = 2000000;

    // Initialize other globals used in loop
    pos = NULL;
    end = NULL;
    new_offset = 0;
    original_offset = 0;
}