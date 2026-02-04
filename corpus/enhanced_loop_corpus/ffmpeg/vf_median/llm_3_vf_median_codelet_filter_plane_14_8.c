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
int shift = (14 + 1) / 2;
int scale = 1 << shift;
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    ptrdiff_t offset = i * src_linesize;
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[offset + j];
        unsigned int high_part = val >> shift;
        unsigned int low_part = val & (scale - 1);

        int fine_index = scale * (width * high_part + j) + low_part;
        int coarse_index = scale * j + high_part;

        // Use strided access pattern by updating every second element in a scattered manner
        if ((j & 1) == 0) {
            if (fine_index + 0 < width * scale * 2) cfine[fine_index + 0]++;
            if (coarse_index + 0 < width * scale) ccoarse[coarse_index + 0]++;
        } else {
            if (fine_index + 1 < width * scale * 2) cfine[fine_index + 1]++;
            if (coarse_index + 1 < width * scale) ccoarse[coarse_index + 1]++;
        }
    }
}
}
