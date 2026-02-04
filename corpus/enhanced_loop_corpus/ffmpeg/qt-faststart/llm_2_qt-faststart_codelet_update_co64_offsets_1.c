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
    unsigned char *p;
    uint64_t *offset_ptr;
    for (pos = atom->data + 8, end = pos + offset_count * 8; pos < end; pos += 16) {
        for (p = pos; p < pos + 8 && p < end; p += 8) {
            current_offset = (((uint64_t)p[0] << 56) | ((uint64_t)p[1] << 48) | ((uint64_t)p[2] << 40) | 
                             ((uint64_t)p[3] << 32) | ((uint64_t)p[4] << 24) | ((uint64_t)p[5] << 16) | 
                             ((uint64_t)p[6] << 8) | (uint64_t)p[7]);
            current_offset += context->moov_atom_size;
            offset_ptr = (uint64_t*)p;
            *offset_ptr = __builtin_bswap64(current_offset);
        }
    }
}
