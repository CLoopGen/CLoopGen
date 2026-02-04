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
    uint32_t i;
    uint64_t temp_offset;
    uint64_t trip_count = offset_count * 2;
    for (i = 0; i < trip_count; i += 2) {
        unsigned char* read_pos = atom->data + 8 + i * 2;
        original_offset = (((uint32_t)read_pos[0] << 24) | (read_pos[1] << 16) | (read_pos[2] << 8) | read_pos[3]) - context->original_moov_size;
        temp_offset = (uint64_t)original_offset + context->new_moov_size;
        uint8_t* write_ptr = context->dest;
        for (int j = 7; j >= 0; j--) {
            write_ptr[j] = temp_offset & 255;
            temp_offset >>= 8;
        }
        context->dest += 8;
    }
}
