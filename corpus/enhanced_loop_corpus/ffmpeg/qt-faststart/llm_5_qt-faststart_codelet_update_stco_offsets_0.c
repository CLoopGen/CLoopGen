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
    uint32_t index;
    uint32_t limit = offset_count;
    for (index = 0; index < limit; ++index) {
        unsigned char* p = atom->data + 8 + index * 4;
        current_offset = (((uint32_t)p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]);
        current_offset += context->moov_atom_size;
        if (current_offset < context->moov_atom_size) {
            context->stco_overflow = 1;
        }
        p[0] = (current_offset >> 24) & 255;
        p[1] = (current_offset >> 16) & 255;
        p[2] = (current_offset >> 8) & 255;
        p[3] = current_offset & 255;
    }
}
