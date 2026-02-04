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
extern uint64_t current_offset;
extern uint32_t offset_count;
extern unsigned char *pos;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = atom->data + 8, end = pos + offset_count * 8; pos < end; pos += 16) {
        if (pos + 8 <= end) {
            current_offset = (((uint64_t)(((uint8_t *)(pos))[0]) << 56) | ((uint64_t)(((uint8_t *)(pos))[1]) << 48) |
                            ((uint64_t)(((uint8_t *)(pos))[2]) << 40) | ((uint64_t)(((uint8_t *)(pos))[3]) << 32) |
                            ((uint64_t)(((uint8_t *)(pos))[4]) << 24) | ((uint64_t)(((uint8_t *)(pos))[5]) << 16) |
                            ((uint64_t)(((uint8_t *)(pos))[6]) << 8) | ((uint64_t)((uint8_t *)(pos))[7]));
            current_offset += context->moov_atom_size;
            ((uint8_t *)(pos))[0] = (current_offset >> 56) & 255;
            ((uint8_t *)(pos))[1] = (current_offset >> 48) & 255;
            ((uint8_t *)(pos))[2] = (current_offset >> 40) & 255;
            ((uint8_t *)(pos))[3] = (current_offset >> 32) & 255;
            ((uint8_t *)(pos + 4))[0] = (current_offset >> 24) & 255;
            ((uint8_t *)(pos + 4))[1] = (current_offset >> 16) & 255;
            ((uint8_t *)(pos + 4))[2] = (current_offset >> 8) & 255;
            ((uint8_t *)(pos + 4))[3] = current_offset & 255;
        }
        if (pos + 16 <= end) {
            uint64_t next_offset = (((uint64_t)(((uint8_t *)(pos + 8))[0]) << 56) | ((uint64_t)(((uint8_t *)(pos + 8))[1]) << 48) |
                                   ((uint64_t)(((uint8_t *)(pos + 8))[2]) << 40) | ((uint64_t)(((uint8_t *)(pos + 8))[3]) << 32) |
                                   ((uint64_t)(((uint8_t *)(pos + 8))[4]) << 24) | ((uint64_t)(((uint8_t *)(pos + 8))[5]) << 16) |
                                   ((uint64_t)(((uint8_t *)(pos + 8))[6]) << 8) | ((uint64_t)((uint8_t *)(pos + 8))[7]));
            next_offset += context->moov_atom_size;
            ((uint8_t *)(pos + 8))[0] = (next_offset >> 56) & 255;
            ((uint8_t *)(pos + 8))[1] = (next_offset >> 48) & 255;
            ((uint8_t *)(pos + 8))[2] = (next_offset >> 40) & 255;
            ((uint8_t *)(pos + 8))[3] = (next_offset >> 32) & 255;
            ((uint8_t *)(pos + 12))[0] = (next_offset >> 24) & 255;
            ((uint8_t *)(pos + 12))[1] = (next_offset >> 16) & 255;
            ((uint8_t *)(pos + 12))[2] = (next_offset >> 8) & 255;
            ((uint8_t *)(pos + 12))[3] = next_offset & 255;
        }
    }
}
