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
for (int i = 0; i < width * 2; i += 2) {
    int idx_fine = ((1 << 6) * (width * ((srcp[i % width]) >> 6) + (i % width)) + ((srcp[i % width]) & 0x3F));
    int idx_coarse = ((1 << 6) * (i % width) + ((srcp[i % width]) >> 6));
    cfine[idx_fine] += radiusV + 1;
    ccoarse[idx_coarse] += radiusV + 1;
}
}
