#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DiracParseContext {
    int state;
    int is_synced;
    int sync_offset;
    int header_bytes_needed;
    int overread_index;
    int buffer_size;
    int index;
    uint8_t *buffer;
    int dirac_unit_size;
    uint8_t *dirac_unit;
} DiracParseContext;

extern DiracParseContext *pc;
extern  uint8_t *buf;
extern int buf_size;
extern uint32_t state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_state = state;
    int found = 0;
    for (i = 0; i < buf_size && !found; i++) {
        temp_state = (temp_state << 8) | buf[i];
        int match = (temp_state == 1111638852);
        pc->is_synced = pc->is_synced | (match && !pc->is_synced);
        pc->header_bytes_needed = match ? 9 : pc->header_bytes_needed;
        pc->sync_offset = match ? i : pc->sync_offset;
        temp_state = match ? -1 : temp_state;
        found = match;
    }
    state = temp_state;
}
