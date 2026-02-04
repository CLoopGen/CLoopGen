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
for (i = 0; i < buf_size; i++) {
    state = (state << 8) | buf[i];
    if (state == 1111638852) {
        state = -1;
        pc->is_synced = 1;
        pc->header_bytes_needed = 9;
        pc->sync_offset = i;
        break;
    }
}

}
