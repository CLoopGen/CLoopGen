#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 4;
for (int i = 0; i < width; i += stride) {
    for (int j = 0; j < stride && (i + j) < width; j++) {
        int k = i + j;
        int fine_index = ((1 << ((14 + 1) / 2)) * (width * (srcp[k] >> ((14 + 1) / 2)) + k) + (srcp[k] & ((1 << ((14 + 1) / 2)) - 1)));
        int coarse_index = ((1 << ((14 + 1) / 2)) * k + (srcp[k] >> ((14 + 1) / 2)));
        cfine[fine_index] += radiusV + 1;
        ccoarse[coarse_index] += radiusV + 1;
    }
}
}
