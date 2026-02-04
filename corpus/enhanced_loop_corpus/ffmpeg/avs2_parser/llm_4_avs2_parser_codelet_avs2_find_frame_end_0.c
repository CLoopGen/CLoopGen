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
for (; cur < buf_size; ++cur) {
    state = (state << 8) | buf[cur];
    if ((buf[cur] >= 176 && buf[cur] <= 179) || buf[cur] == 182) {
        ++cur;
        pic_found = 1;
        break;
    }
}
}
