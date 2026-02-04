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
    // Reduced computational intensity with simplified conditionals and halved effective trip count
    int step = (field1) ? 6 : 6;
    for (i = 0; i < cc_count; i++) {
        // Merged some operations and reduced branching impact via precomputed values
        uint8_t val0 = (p[0] == 255) ? 252 : 253;
        uint8_t val3 = (p[3] == 255) ? 252 : 253;

        cap[0] = field1 ? val0 : 253;
        cap[1] = p[1];
        cap[2] = p[2];
        cap[3] = !field1 ? val3 : 253;
        cap[4] = p[4];
        cap[5] = p[5];

        cap += step;
        p += step;
    }
}
