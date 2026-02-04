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
for (int i = 0; i < width; i += 2) {
    if (i < width) {
        cfine[((1 << 7) * (width * (srcp[i] >> 7) + i) + (srcp[i] & 0x7F))] += radiusV + 1;
        ccoarse[((1 << 7) * i + (srcp[i] >> 7))] += radiusV + 1;
    }
    if (i + 1 < width) {
        cfine[((1 << 7) * (width * (srcp[i+1] >> 7) + (i+1)) + (srcp[i+1] & 0x7F))] += radiusV + 1;
        ccoarse[((1 << 7) * (i+1) + (srcp[i+1] >> 7))] += radiusV + 1;
    }
}
}
