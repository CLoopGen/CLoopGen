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
    int idx_fine1 = ((1 << ((12 + 1) / 2)) * (width * ((srcp[i]) >> ((12 + 1) / 2)) + i) + ((srcp[i]) & ((1 << ((12 + 1) / 2)) - 1)));
    ccoarse[((1 << ((12 + 1) / 2)) * i + ((srcp[i]) >> ((12 + 1) / 2)))] += radiusV + 1;
    if (i + 1 < width) {
        int idx_fine2 = ((1 << ((12 + 1) / 2)) * (width * ((srcp[i+1]) >> ((12 + 1) / 2)) + (i+1)) + ((srcp[i+1]) & ((1 << ((12 + 1) / 2)) - 1)));
        cfine[idx_fine2] += radiusV + 1;
        ccoarse[((1 << ((12 + 1) / 2)) * (i+1) + ((srcp[i+1]) >> ((12 + 1) / 2)))] += radiusV + 1;
    }
    cfine[idx_fine1] += radiusV + 1;
}
}
