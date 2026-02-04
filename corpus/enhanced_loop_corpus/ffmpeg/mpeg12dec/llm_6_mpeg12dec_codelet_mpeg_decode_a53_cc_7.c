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
    uint8_t temp1, temp2, temp3, temp4, temp5, temp6;
    for (i = 0; i < cc_count; i++) {
        temp1 = p[0]; temp2 = p[1]; temp3 = p[2];
        temp4 = p[3]; temp5 = p[4]; temp6 = p[5];

        cap[0] = (temp1 == 255 && field1) ? 252 : 253;
        cap[1] = temp2;
        cap[2] = temp3;
        cap[3] = (temp4 == 255 && !field1) ? 252 : 253;
        cap[4] = temp5;
        cap[5] = temp6;

        cap += 6;
        p += 6;
    }
}
