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
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    int threshold = (1 << ((16 + 1) / 2)) >> 1;
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[j];
        int high_bits = val >> ((16 + 1) / 2);
        int low_bits = val & ((1 << ((16 + 1) / 2)) - 1);
        
        if (high_bits < threshold) {
            cfine[((1 << ((16 + 1) / 2)) * (width * high_bits + j) + low_bits)]++;
        } else {
            ccoarse[((1 << ((16 + 1) / 2)) * j + high_bits)]++;
        }
    }
    srcp += src_linesize;
}
}
