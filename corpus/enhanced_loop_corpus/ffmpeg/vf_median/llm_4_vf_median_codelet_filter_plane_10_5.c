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
    if ((srcp[i] & ((1 << ((10 + 1) / 2)) - 1)) < (1 << ((10 + 1) / 2))) {
        cfine[((1 << ((10 + 1) / 2)) * (width * (srcp[i] >> ((10 + 1) / 2)) + i) + (srcp[i] & ((1 << ((10 + 1) / 2)) - 1)))] += radiusV + 1;
    }
    ccoarse[((1 << ((10 + 1) / 2)) * i + (srcp[i] >> ((10 + 1) / 2)))] += radiusV + 1;
}
}
