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
        int offset_coarse_base = (1 << ((12 + 1) / 2));
        int shift = (12 + 1) / 2;
        int mask = (1 << shift) - 1;
        for (int j = 0; j < width; j++) {
            int val = srcp[j];
            int high_part = val >> shift;
            int low_part = val & mask;
            int fine_index = offset_coarse_base * (width * high_part + j) + low_part;
            int coarse_index = offset_coarse_base * j + high_part;
            // Introduce artificial WAW dependency by updating cfine before ccoarse and reusing index calculations
            cfine[fine_index] += 1;
            ccoarse[coarse_index] += 1;
        }
        srcp += src_linesize;
    }
}
