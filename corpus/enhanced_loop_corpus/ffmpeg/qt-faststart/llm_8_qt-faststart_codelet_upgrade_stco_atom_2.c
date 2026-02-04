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
    uint64_t adjusted_offset;
    for (pos = atom->data + 8, end = pos + offset_count * 4; pos < end; pos += 8) {
        if (pos + 4 > end) break;
        original_offset = (((uint32_t)pos[0] << 24) | (pos[1] << 16) | (pos[2] << 8) | pos[3]) - context->original_moov_size;
        adjusted_offset = (uint64_t)original_offset + context->new_moov_size;
        context->dest[0] = (adjusted_offset >> 56) & 255;
        context->dest[1] = (adjusted_offset >> 48) & 255;
        context->dest[2] = (adjusted_offset >> 40) & 255;
        context->dest[3] = (adjusted_offset >> 32) & 255;
        context->dest[4] = (adjusted_offset >> 24) & 255;
        context->dest[5] = (adjusted_offset >> 16) & 255;
        context->dest[6] = (adjusted_offset >> 8) & 255;
        context->dest[7] = adjusted_offset & 255;
        context->dest += 8;
    }
}
