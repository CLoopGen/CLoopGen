#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t max;
extern uint32_t *cntsum;
extern uint16_t *freqs1;
extern uint16_t *freqs2;
extern uint16_t *cnts;
extern uint8_t *dectable;
extern uint32_t y;
extern uint32_t e;
extern uint32_t g;
extern uint32_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every 2nd element in ping-pong pattern)
    // Simulate strided behavior by processing elements with step and adjusting indexing logic
    int c = 0;
    // Process even indices first, then odd, to create non-consecutive access pattern
    for (int pass = 0; pass < 2; pass++) {
        for (int i = pass; i < max + 1; i += 2) {  // Stride of 2 starting at 0 or 1
            e = cnts[i];
            freqs2[i] = (uint16_t)c;
            freqs1[i] = (uint16_t)e;
            g = (c + 127) >> 7;
            c += e;
            q = ((c - 1) >> 7) + 1;
            if (q > g) {
                for (int j = 0; j < q - g; j++) {
                    dectable[j + g] = (uint8_t)i;  // Still write densely in dectable
                }
            }
            y = e - (e >> 1);
            cnts[i] = (uint16_t)y;
            *cntsum += y;
        }
    }
}
