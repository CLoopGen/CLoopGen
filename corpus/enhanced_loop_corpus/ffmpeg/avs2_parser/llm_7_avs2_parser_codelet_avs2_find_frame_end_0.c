#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int pic_found;
extern uint32_t state;
extern int cur;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_state = state;
    int local_cur = cur;
    for (; local_cur < buf_size; ++local_cur) {
        local_state = (local_state << 8) | buf[local_cur];
        if ((buf[local_cur] == 176 || buf[local_cur] == 177 || buf[local_cur] == 178 || (buf[local_cur] == 179 || buf[local_cur] == 182))) {
            local_cur++;
            pic_found = 1;
            break;
        }
    }
    // Remove WAW and WAR dependencies on 'cur' and 'state' via local copies
    cur = local_cur;
    state = local_state;
}
