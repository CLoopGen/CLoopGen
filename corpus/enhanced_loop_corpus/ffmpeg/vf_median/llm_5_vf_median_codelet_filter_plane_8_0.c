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
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
        for (int j = 0; j < width; j++) {
            uint16_t val = srcp[j];
            int shift = (8 + 1) / 2;
            int index_fine = (1 << shift) * (width * (val >> shift) + j) + (val & ((1 << shift) - 1));
            int index_coarse = (1 << shift) * j + (val >> shift);

            if (val > 0) {
                cfine[index_fine]++;
                if (val < 128) {
                    ccoarse[index_coarse]++;
                }
            } else {
                ccoarse[index_coarse] += 2;
            }
        }
        srcp += src_linesize;
    }
}
