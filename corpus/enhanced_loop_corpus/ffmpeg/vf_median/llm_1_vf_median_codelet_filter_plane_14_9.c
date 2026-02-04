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
for (int k = 0; k < width * 2; k++) {
    int i = k / 2;
    if (k % 2 == 0 && i < width) {
        cfine[((1 << ((14 + 1) / 2)) * ((width) * ((srcp[i]) >> ((14 + 1) / 2)) + (i)) + ((srcp[i]) & ((1 << ((14 + 1) / 2)) - 1)))] += radiusV + 1;
    } else if (i < width) {
        ccoarse[((1 << ((14 + 1) / 2)) * (i) + ((srcp[i]) >> ((14 + 1) / 2)))] += radiusV + 1;
    }
}
}
