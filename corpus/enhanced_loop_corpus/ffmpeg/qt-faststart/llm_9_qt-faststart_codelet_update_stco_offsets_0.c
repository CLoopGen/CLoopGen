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



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and trip count reduction
    // Simulate processing every other entry (half the iterations), less dense arithmetic

    pos = atom->data + 8;
    end = pos + offset_count * 4;

    // Process only every second offset to reduce trip count
    for (; pos < end; pos += 8) {  // Step by 8 instead of 4
        current_offset = (((uint32_t)(pos[0]) << 24) | (pos[1] << 16) | (pos[2] << 8) | pos[3]);

        // Simplified overflow check using precomputed threshold
        uint64_t max_allowed = (2147483647ULL * 2U + 1U) - context->moov_atom_size;
        if (current_offset > max_allowed) {
            context->stco_overflow = 1;
            break; // Early exit on overflow to reduce computation further
        }

        current_offset += context->moov_atom_size;

        // Write back updated offset
        pos[0] = (current_offset >> 24) & 255;
        pos[1] = (current_offset >> 16) & 255;
        pos[2] = (current_offset >> 8) & 255;
        pos[3] = current_offset & 255;
    }

    // Note: This variant trades completeness for lower computational load — suitable for sampling or preview scenarios.
}
