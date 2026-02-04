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
    uint64_t i;
    uint64_t *base = (uint64_t*)(atom->data + 8);
    uint64_t count = offset_count;
    for (i = 0; i < count; i++) {
        current_offset = __builtin_bswap64(base[i]) + context->moov_atom_size;
        base[i] = __builtin_bswap64(current_offset);
    }
}
