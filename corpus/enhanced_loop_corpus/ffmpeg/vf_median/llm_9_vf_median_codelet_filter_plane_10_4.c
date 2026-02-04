#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int unroll_factor = 4;
int aligned_width = (width / unroll_factor) * unroll_factor;
for (int i = 0; i < radiusV + (jobnr != 0); i++) {
    for (int j = 0; j < aligned_width; j += unroll_factor) {
        #pragma GCC unroll 4
        for (int k = 0; k < unroll_factor; k++) {
            uint16_t val = srcp[j + k];
            int shift = (10 + 1) / 2;
            cfine[((1 << shift) * (width * (val >> shift) + (j + k)) + (val & ((1 << shift) - 1)))]++;
            ccoarse[((1 << shift) * (j + k) + (val >> shift))]++;
        }
    }
    for (int j = aligned_width; j < width; j++) {
        uint16_t val = srcp[j];
        int shift = (10 + 1) / 2;
        cfine[((1 << shift) * (width * (val >> shift) + j) + (val & ((1 << shift) - 1)))]++;
        ccoarse[((1 << shift) * j + (val >> shift))]++;
    }
    srcp += src_linesize;
}
}
