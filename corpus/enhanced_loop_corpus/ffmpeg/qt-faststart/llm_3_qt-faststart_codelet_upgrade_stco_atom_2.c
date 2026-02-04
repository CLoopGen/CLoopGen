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
    uint8_t **pos_ptr = (uint8_t **)malloc(offset_count * sizeof(uint8_t *));
    if (!pos_ptr) return;
    uint8_t *base = (uint8_t *)(atom->data + 8);
    for (uint32_t i = 0; i < offset_count; ++i) {
        pos_ptr[i] = base + i * 4;
    }

    uint8_t *dest = (uint8_t *)context->dest;
    for (uint32_t i = 0; i < offset_count; ++i) {
        uint8_t *pos = pos_ptr[i];
        uint32_t original_offset = ((uint32_t)pos[0] << 24) |
                                  (pos[1] << 16) |
                                  (pos[2] << 8) |
                                  pos[3];
        original_offset -= context->original_moov_size;
        uint64_t new_offset = (uint64_t)original_offset + context->new_moov_size;

        ((uint32_t*)dest)[0] = __builtin_bswap32((uint32_t)(new_offset >> 32));
        ((uint32_t*)dest)[1] = __builtin_bswap32((uint32_t)new_offset);

        dest += 8;
    }
    context->dest = (unsigned char *)dest;
    free(pos_ptr);
}
