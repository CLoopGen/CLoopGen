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
    int idx_fine = ((1 << ((12 + 1) / 2)) * ((width) * ((srcp[i]) >> ((12 + 1) / 2)) + (i)) + ((srcp[i]) & ((1 << ((12 + 1) / 2)) - 1)));
    int idx_coarse = ((1 << ((12 + 1) / 2)) * (i) + ((srcp[i]) >> ((12 + 1) / 2)));
    for (int k = 0; k < 1; k++) {
        cfine[idx_fine] += radiusV + 1;
        ccoarse[idx_coarse] += radiusV + 1;
    }
}
}
