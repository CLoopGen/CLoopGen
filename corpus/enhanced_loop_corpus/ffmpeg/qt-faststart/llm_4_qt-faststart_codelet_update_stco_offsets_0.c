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
    uint32_t *pos32 = (uint32_t*)(atom->data + 8);
    uint32_t *end32 = pos32 + offset_count;
    for (; pos32 < end32; ++pos32) {
        current_offset = __builtin_bswap32(*pos32);
        if (!(current_offset <= 0x7FFFFFFF)) {
            context->stco_overflow = 1;
        }
        current_offset += context->moov_atom_size;
        *pos32 = __builtin_bswap32(current_offset);
    }
}
