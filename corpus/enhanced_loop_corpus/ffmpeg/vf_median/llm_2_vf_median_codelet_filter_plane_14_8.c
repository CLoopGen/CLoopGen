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
    uint16_t *src_line = srcp + i * src_linesize;
    for (int j = 0; j < width; j += 2) {
        int idx_fine1 = ((1 << ((14 + 1) / 2)) * (width * ((src_line[j]) >> ((14 + 1) / 2)) + j) + ((src_line[j]) & ((1 << ((14 + 1) / 2)) - 1)));
        int idx_coarse1 = ((1 << ((14 + 1) / 2)) * j + ((src_line[j]) >> ((14 + 1) / 2)));
        
        if (idx_fine1 < width * (1 << ((14 + 1))) && idx_coarse1 < width * (1 << ((14 + 1) / 2)))
            cfine[idx_fine1]++;
        if (idx_coarse1 < width * (1 << ((14 + 1) / 2)))
            ccoarse[idx_coarse1]++;

        if (j + 1 < width) {
            int idx_fine2 = ((1 << ((14 + 1) / 2)) * (width * ((src_line[j+1]) >> ((14 + 1) / 2)) + (j+1)) + ((src_line[j+1]) & ((1 << ((14 + 1) / 2)) - 1)));
            int idx_coarse2 = ((1 << ((14 + 1) / 2)) * (j+1) + ((src_line[j+1]) >> ((14 + 1) / 2)));

            if (idx_fine2 < width * (1 << ((14 + 1))) && idx_coarse2 < width * (1 << ((14 + 1) / 2)))
                cfine[idx_fine2]++;
            if (idx_coarse2 < width * (1 << ((14 + 1) / 2)))
                ccoarse[idx_coarse2]++;
        }
    }
}
}
