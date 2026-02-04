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
    unsigned char *local_pos;
    uint64_t local_offset;
    uint64_t base_moov_size = context->moov_atom_size;
    for (local_pos = atom->data + 8; local_pos < atom->data + 8 + offset_count * 8; local_pos += 8) {
        local_offset = (((uint64_t)((uint8_t *)(local_pos))[0] << 56) |
                       ((uint64_t)((uint8_t *)(local_pos))[1] << 48) |
                       ((uint64_t)((uint8_t *)(local_pos))[2] << 40) |
                       ((uint64_t)((uint8_t *)(local_pos))[3] << 32) |
                       ((uint64_t)((uint8_t *)(local_pos))[4] << 24) |
                       ((uint64_t)((uint8_t *)(local_pos))[5] << 16) |
                       ((uint64_t)((uint8_t *)(local_pos))[6] << 8)  |
                       ((uint64_t)((uint8_t *)(local_pos))[7]));

        local_offset += base_moov_size;

        ((uint8_t *)(local_pos))[0] = (uint8_t)(local_offset >> 56);
        ((uint8_t *)(local_pos))[1] = (uint8_t)(local_offset >> 48);
        ((uint8_t *)(local_pos))[2] = (uint8_t)(local_offset >> 40);
        ((uint8_t *)(local_pos))[3] = (uint8_t)(local_offset >> 32);
        ((uint8_t *)(local_pos))[4] = (uint8_t)(local_offset >> 24);
        ((uint8_t *)(local_pos))[5] = (uint8_t)(local_offset >> 16);
        ((uint8_t *)(local_pos))[6] = (uint8_t)(local_offset >> 8);
        ((uint8_t *)(local_pos))[7] = (uint8_t)(local_offset);

        current_offset = local_offset;
    }
}
