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
for (int i = 0; i < width; i++) {
    int fine_index = (1 << ((10 + 1) / 2)) * (width * (srcp[i] >> ((10 + 1) / 2)) + i) + (srcp[i] & ((1 << ((10 + 1) / 2)) - 1));
    int coarse_index = (1 << ((10 + 1) / 2)) * i + (srcp[i] >> ((10 + 1) / 2));

    if (fine_index >= 0) {
        cfine[fine_index] += radiusV + 1;
    }
    if (coarse_index >= 0) {
        ccoarse[coarse_index] += radiusV + 1;
    }
}
}
