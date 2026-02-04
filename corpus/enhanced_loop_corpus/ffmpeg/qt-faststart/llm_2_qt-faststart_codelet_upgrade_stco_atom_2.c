#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern upgrade_stco_context_t *context;
extern atom_t *atom;
extern unsigned char *pos;
extern unsigned char *end;
extern uint64_t new_offset;
extern uint32_t offset_count;
extern uint32_t original_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *data_ptr = (uint8_t *)(atom->data + 8);
    uint8_t *dest_ptr = (uint8_t *)(context->dest);
    uint64_t limit = offset_count * 4;
    for (uint32_t i = 0; i < limit; i += 4) {
        uint32_t original_offset = ((uint32_t)data_ptr[i + 0] << 24) |
                                   (data_ptr[i + 1] << 16) |
                                   (data_ptr[i + 2] << 8) |
                                   data_ptr[i + 3];
        original_offset -= context->original_moov_size;
        uint64_t new_offset = (uint64_t)original_offset + context->new_moov_size;

        dest_ptr[0] = (uint8_t)((new_offset >> 56) & 0xFF);
        dest_ptr[1] = (uint8_t)((new_offset >> 48) & 0xFF);
        dest_ptr[2] = (uint8_t)((new_offset >> 40) & 0xFF);
        dest_ptr[3] = (uint8_t)((new_offset >> 32) & 0xFF);
        dest_ptr[4] = (uint8_t)((new_offset >> 24) & 0xFF);
        dest_ptr[5] = (uint8_t)((new_offset >> 16) & 0xFF);
        dest_ptr[6] = (uint8_t)((new_offset >> 8) & 0xFF);
        dest_ptr[7] = (uint8_t)(new_offset & 0xFF);

        dest_ptr += 8;
    }
    context->dest = (unsigned char *)dest_ptr;
}
