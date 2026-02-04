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
for (; cur < buf_size && !pic_found; ++cur) {
    state = (state << 8) | buf[cur];
    uint8_t b = buf[cur];
    if (b == 176) goto found;
    if (b == 177) goto found;
    if (b == 178) goto found;
    if (b == 179) goto found;
    if (b == 182) goto found;
    continue;
found:
    ++cur;
    pic_found = 1;
    break;
}
}
