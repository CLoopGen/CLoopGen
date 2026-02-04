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
uint32_t c = 0;
for (uint32_t i = 0; i < (max + 1) && i < 65536u; i += 2) {
    uint32_t e1 = cnts[i];
    uint32_t e2 = (i + 1 < max + 1) ? cnts[i + 1] : 0;
    freqs2[i] = c;
    freqs1[i] = e1;
    c += e1;
    if (i + 1 < max + 1) {
        freqs2[i + 1] = c;
        freqs1[i + 1] = e2;
        c += e2;
    }
    uint32_t g1 = (freqs2[i] + 127) >> 7;
    uint32_t q1 = ((freqs2[i] + e1 - 1) >> 7) + 1;
    if (q1 > g1) {
        for (int j = 0; j < (q1 - g1); j++)
            dectable[j + g1] = i;
    }
    if (e2 > 0 && i + 1 < max + 1) {
        uint32_t g2 = (freqs2[i + 1] + 127) >> 7;
        uint32_t q2 = ((freqs2[i + 1] + e2 - 1) >> 7) + 1;
        if (q2 > g2) {
            for (int j = 0; j < (q2 - g2); j++)
                dectable[j + g2] = i + 1;
        }
    }
    uint32_t y1 = e1 - (e1 >> 1);
    uint32_t y2 = e2 - (e2 >> 1);
    cnts[i] = y1;
    *cntsum += y1;
    if (i + 1 < max + 1) {
        cnts[i + 1] = y2;
        *cntsum += y2;
    }
}
}
