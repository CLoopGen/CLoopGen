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
    uint32_t local_state = state;
    int local_synced = pc->is_synced;
    int local_header_bytes = pc->header_bytes_needed;
    int local_sync_offset = pc->sync_offset;
    for (i = 0; i < buf_size; i++) {
        local_state = (local_state << 8) | buf[i];
        if (local_state == 1111638852) {
            local_state = -1;
            local_synced = 1;
            local_header_bytes = 9;
            local_sync_offset = i;
            break;
        }
    }
    state = local_state;
    pc->is_synced = local_synced;
    pc->header_bytes_needed = local_header_bytes;
    pc->sync_offset = local_sync_offset;
}
