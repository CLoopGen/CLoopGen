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
    uint16_t temp_fine[1024] = {0}; // Local accumulation to remove WAW hazards
    uint16_t temp_coarse[1024] = {0}; // Local accumulation for coarse as well
    for (int j = 0; j < width; j++) {
        int index_fine = ((1 << ((9 + 1) / 2)) * ((width) * ((srcp[j]) >> ((9 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((9 + 1) / 2)) - 1)));
        int index_coarse = ((1 << ((9 + 1) / 2)) * (j) + ((srcp[j]) >> ((9 + 1) / 2)));
        temp_fine[index_fine % 1024]++;
        temp_coarse[index_coarse % 1024]++;
    }
    // Flush local accumulators to global arrays to eliminate loop-carried dependencies
    for (int k = 0; k < 1024; k++) {
        if (temp_fine[k]) cfine[k] += temp_fine[k];
        if (temp_coarse[k]) ccoarse[k] += temp_coarse[k];
    }
    srcp += src_linesize;
}
}
