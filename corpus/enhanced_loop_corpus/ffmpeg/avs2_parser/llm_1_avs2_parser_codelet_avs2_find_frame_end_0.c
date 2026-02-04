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
for (int outer = cur; outer < buf_size; outer += 16) {
    for (int inner = outer; inner < outer + 16 && inner < buf_size; ++inner) {
        state = (state << 8) | buf[inner];
        if ((buf[inner]) == 176 || (buf[inner]) == 177 || (buf[inner]) == 178 || (buf[inner]) == 179 || (buf[inner]) == 182) {
            cur = inner + 1;
            pic_found = 1;
            return;
        }
    }
}
}
