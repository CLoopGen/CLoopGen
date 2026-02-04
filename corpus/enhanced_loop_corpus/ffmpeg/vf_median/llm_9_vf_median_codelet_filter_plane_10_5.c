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
        ccoarse[((1 << 5) * i + ((srcp[i]) >> 5))] += radiusV + 1;
        cfine[((1 << 5) * (width * ((srcp[i]) >> 5) + i) + ((srcp[i]) & 0x1F))] += radiusV + 1;
    }
    if (i + 1 < width) {
        ccoarse[((1 << 5) * (i + 1) + ((srcp[i + 1]) >> 5))] += radiusV + 1;
        cfine[((1 << 5) * (width * ((srcp[i + 1]) >> 5) + (i + 1)) + ((srcp[i + 1]) & 0x1F))] += radiusV + 1;
    }
}
}
