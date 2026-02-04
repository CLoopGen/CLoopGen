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
    uint64_t temp_offset;
    for (pos = atom->data + 8, end = pos + offset_count * 4; pos < end; pos += 4) {
        original_offset = (((uint32_t)(((uint8_t *)(pos))[0]) << 24) |
                          ((uint32_t)(((uint8_t *)(pos))[1]) << 16) |
                          ((uint32_t)(((uint8_t *)(pos))[2]) << 8)  |
                          ((uint32_t)(((uint8_t *)(pos))[3])) ) - context->original_moov_size;

        new_offset = (uint64_t)original_offset + context->new_moov_size;

        temp_offset = new_offset;

        ((uint32_t*)(context->dest))[0] = __builtin_bswap32((uint32_t)(temp_offset >> 32));
        ((uint32_t*)(context->dest))[1] = __builtin_bswap32((uint32_t)(temp_offset & 0xFFFFFFFF));

        context->dest += 8;
    }
}
