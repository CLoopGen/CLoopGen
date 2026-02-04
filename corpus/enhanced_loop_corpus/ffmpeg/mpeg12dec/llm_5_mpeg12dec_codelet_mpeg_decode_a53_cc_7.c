#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern int cc_count;
extern int i;
extern uint8_t field1;
extern uint8_t *cap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cc_count; i++) {
    if (!(field1 && p[0] == 255)) {
        cap[0] = 253;
    } else {
        cap[0] = 252;
    }
    cap[1] = p[1];
    cap[2] = p[2];
    if (!(!field1 && p[3] == 255)) {
        cap[3] = 253;
    } else {
        cap[3] = 252;
    }
    cap[4] = p[4];
    cap[5] = p[5];
    cap += 6;
    p += 6;
}
}
