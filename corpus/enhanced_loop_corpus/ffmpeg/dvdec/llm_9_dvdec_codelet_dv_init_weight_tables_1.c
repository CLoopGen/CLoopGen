#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_dv_quant_shifts[22][4];
extern  uint16_t dv_iweight_248[64];
extern int j;
extern int i;
extern int c;
extern int s;
extern uint32_t *factor1;
extern uint32_t *factor2;
extern  uint8_t dv_quant_areas[4];
extern  uint16_t *iweight1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 1; j++, iweight1 = &dv_iweight_248[0]) {
    for (s = 0; s < 44; s += 2) {
        for (c = 0; c < 2; c++) {
            int limit = dv_quant_areas[c] >> 1;
            for (i = 0; i < limit; i++) {
                *factor1 = (iweight1[i] << ff_dv_quant_shifts[s % 22][c]) << 1;
                factor1++;
                *factor2 = *factor1;
                factor2++;
            }
        }
    }
}
}
