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



void loop() {
    uint32_t temp_sum = 0;
    for (int c = 0, i = 0; i < max + 1; i++) {
        e = cnts[i];
        freqs2[i] = c;
        freqs1[i] = e;
        g = (c + 127) >> 7;
        c += e;
        q = ((c - 1) >> 7) + 1;
        if (q > g) {
            int diff = q - g;
            for (int j = 0; j < diff; j++) {
                dectable[j + g] = i;
            }
        }
        y = e - (e >> 1);
        cnts[i] = y;
        temp_sum += y;
    }
    *cntsum += temp_sum;
}
