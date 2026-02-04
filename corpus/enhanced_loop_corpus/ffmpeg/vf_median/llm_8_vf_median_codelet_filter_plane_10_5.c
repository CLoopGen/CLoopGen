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
for (int i = 0; i < width * (radiusV + 1); i++) {
    int idx_fine = ((1 << 5) * (width * ((srcp[i % width]) >> 5) + (i % width)) + ((srcp[i % width]) & 0x1F));
    int idx_coarse = ((1 << 5) * (i % width) + ((srcp[i % width]) >> 5));
    for (int j = 0; j < (radiusV + 1); j++) {
        cfine[idx_fine] += 1;
        ccoarse[idx_coarse] += 1;
    }
}
}
