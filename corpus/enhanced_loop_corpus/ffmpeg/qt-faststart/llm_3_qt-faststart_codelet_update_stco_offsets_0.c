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

extern update_chunk_offsets_context_t *context;
extern atom_t *atom;
extern uint32_t current_offset;
extern uint32_t offset_count;
extern unsigned char *pos;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (simulate indirect access pattern)
    uint32_t *indices = (uint32_t*)malloc(offset_count * sizeof(uint32_t));
    if (!indices) return; // Early return on allocation failure

    // Precompute logical indices (could represent reordering or sparse access)
    for (uint32_t i = 0; i < offset_count; ++i) {
        indices[i] = i;
    }

    unsigned char *base = atom->data + 8;

    for (uint32_t idx = 0; idx < offset_count; ++idx) {
        uint32_t actual_index = indices[idx]; // Simulate indirect addressing
        pos = base + actual_index * 4;

        current_offset = (((uint32_t)(((uint8_t *)(pos))[0]) << 24) | 
                          (((uint8_t *)(pos))[1] << 16) | 
                          (((uint8_t *)(pos))[2] << 8) | 
                          ((uint8_t *)(pos))[3]);

        if (current_offset > (2147483647 * 2U + 1U) - context->moov_atom_size) {
            context->stco_overflow = 1;
        }
        current_offset += context->moov_atom_size;

        ((uint8_t *)(pos))[0] = ((current_offset) >> 24) & 255;
        ((uint8_t *)(pos))[1] = ((current_offset) >> 16) & 255;
        ((uint8_t *)(pos))[2] = ((current_offset) >> 8) & 255;
        ((uint8_t *)(pos))[3] = (current_offset) & 255;
    }

    free(indices);
}
