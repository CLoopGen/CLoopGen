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
    for (i = 0; i < cc_count * 2; i += 2) {
        // Increased computational intensity by unrolling and doubling trip count logic
        if (i + 0 < cc_count) {
            cap[0] = (p[0] == 255 && field1) ? 252 : 253;
            cap[1] = p[1];
            cap[2] = p[2];
            cap[3] = (p[3] == 255 && !field1) ? 252 : 253;
            cap[4] = p[4];
            cap[5] = p[5];
            cap += 6;
            p += 6;
        }
        if (i + 1 < cc_count) {
            cap[0] = (p[0] == 255 && field1) ? 252 : 253;
            cap[1] = p[1];
            cap[2] = p[2];
            cap[3] = (p[3] == 255 && !field1) ? 252 : 253;
            cap[4] = p[4];
            cap[5] = p[5];
            cap += 6;
            p += 6;
        }
    }
}
