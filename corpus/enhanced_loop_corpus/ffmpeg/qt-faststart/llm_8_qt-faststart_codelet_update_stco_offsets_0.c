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
    // Variant 1: Increased computational intensity with unrolled loop (2x unroll) and additional arithmetic operations
    pos = atom->data + 8;
    end = pos + offset_count * 4;

    // Handle unaligned start if needed (simplified assumption: offset_count is even)
    for (; pos <= end - 8; pos += 8) {
        uint32_t offset1 = (((uint32_t)(pos[0]) << 24) | (pos[1] << 16) | (pos[2] << 8) | pos[3]);
        uint32_t offset2 = (((uint32_t)(pos[4]) << 24) | (pos[5] << 16) | (pos[6] << 8) | pos[7]);

        // Additional arithmetic: simulate extra computation (e.g., scaling moov_atom_size)
        uint64_t adjusted_moov = context->moov_atom_size + (context->depth * 2); // extra work

        if (offset1 > (2147483647ULL * 2U + 1U) - adjusted_moov ||
            offset2 > (2147483647ULL * 2U + 1U) - adjusted_moov) {
            context->stco_overflow = 1;
        }

        offset1 += adjusted_moov;
        offset2 += adjusted_moov;

        // Update both offsets with expanded bit manipulation
        pos[0] = (offset1 >> 24) & 255; pos[1] = (offset1 >> 16) & 255;
        pos[2] = (offset1 >> 8) & 255;  pos[3] = offset1 & 255;

        pos[4] = (offset2 >> 24) & 255; pos[5] = (offset2 >> 16) & 255;
        pos[6] = (offset2 >> 8) & 255;  pos[7] = offset2 & 255;
    }

    // Handle remaining element if any
    for (; pos < end; pos += 4) {
        current_offset = (((uint32_t)(pos[0]) << 24) | (pos[1] << 16) | (pos[2] << 8) | pos[3]);
        if (current_offset > (2147483647ULL * 2U + 1U) - context->moov_atom_size) {
            context->stco_overflow = 1;
        }
        current_offset += context->moov_atom_size;
        pos[0] = (current_offset >> 24) & 255;
        pos[1] = (current_offset >> 16) & 255;
        pos[2] = (current_offset >> 8) & 255;
        pos[3] = current_offset & 255;
    }
}
