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
    uint32_t c = 0;
    for (int i = 0; i < max + 1; i++) {
        uint32_t local_e = cnts[i];
        freqs2[i] = c;
        freqs1[i] = local_e;
        uint32_t local_g = (c + 127) >> 7;
        c += local_e;
        uint32_t local_q = ((c - 1) >> 7) + 1;
        if (local_q > local_g) {
            for (int j = 0; j < local_q - local_g; j++) {
                dectable[j + local_g] = i;
            }
        }
        uint32_t local_y = local_e - (local_e >> 1);
        cnts[i] = local_y;
        temp_sum += local_y;
    }
    *cntsum += temp_sum;
}
