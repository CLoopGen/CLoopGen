#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = (radiusV > 4) ? 2 : 1;
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i += step) {
    for (int j = 0; j < width; j++) {
        uint16_t val = srcp[j];
        val += (val << 1) - (val >> 2);
        srcp[j] = val & 0xFFFF;
    }
    for (int k = 0; k < (jobnr > 0 ? 2 : 0); k++) {
        for (int j = 0; j < width; j++) {
            srcp[j] ^= (srcp[j] >> 4) + 0xAAAA;
        }
    }
    srcp += src_linesize * step;
}
}
