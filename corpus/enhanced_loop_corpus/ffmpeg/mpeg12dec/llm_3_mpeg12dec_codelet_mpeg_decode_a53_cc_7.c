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
    // Variant 2: Strided memory access - process every second element pair first, then fill in
    // Simulate a strided pattern by accessing elements with step > 1, but over unrolled pairs
    for (i = 0; i < cc_count; i++) {
        // Access even indices first (0, 2, 4), then odd (1, 3, 5) — artificial stride of 2
        cap[0] = (p[0] == 255 && field1) ? 252 : 253;
        cap[2] = p[2];
        cap[4] = p[4];

        cap[1] = p[1];
        cap[3] = (p[3] == 255 && !field1) ? 252 : 253;
        cap[5] = p[5];

        cap += 6;
        p += 6;
    }
}
