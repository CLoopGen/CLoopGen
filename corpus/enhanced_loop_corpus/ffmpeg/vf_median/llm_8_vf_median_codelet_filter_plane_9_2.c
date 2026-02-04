#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    for (int j = 0; j < width; j += 2) {
        int val1 = srcp[j];
        int shifted = val1 >> ((9 + 1) / 2);
        int masked = val1 & ((1 << ((9 + 1) / 2)) - 1);
        int index_fine = (1 << ((9 + 1) / 2)) * (width * shifted + j) + masked;
        int index_coarse = (1 << ((9 + 1) / 2)) * j + shifted;
        cfine[index_fine]++;
        ccoarse[index_coarse]++;
        
        if (j + 1 < width) {
            int val2 = srcp[j + 1];
            int shifted2 = val2 >> ((9 + 1) / 2);
            int masked2 = val2 & ((1 << ((9 + 1) / 2)) - 1);
            int index_fine2 = (1 << ((9 + 1) / 2)) * (width * shifted2 + (j + 1)) + masked2;
            int index_coarse2 = (1 << ((9 + 1) / 2)) * (j + 1) + shifted2;
            cfine[index_fine2]++;
            ccoarse[index_coarse2]++;
        }
    }
    srcp += src_linesize;
}
}
