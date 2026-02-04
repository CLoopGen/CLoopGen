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
int i = cur;
for (; i < buf_size; ++i) {
    state = (state << 8) | buf[i];
    if ((buf[i]) == 176 || (buf[i]) == 177 || (buf[i]) == 178 || (buf[i]) == 179 || (buf[i]) == 182) {
        cur = i + 1;
        pic_found = 1;
        break;
    }
}
}
