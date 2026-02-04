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
for (int i = 0; i < radiusV + (jobnr != 0) * (1 + radiusV); i++) {
    for (int j = 0; j < width; j += 2) {
        uint16_t temp1 = srcp[j] + 1;
        uint16_t temp2 = srcp[j] * 3 + 5;
        srcp[j] = (temp1 ^ temp2) & 0xFFFF;
        if (j + 1 < width) {
            srcp[j + 1] = (srcp[j + 1] * 2 + 1) & 0xFFFF;
        }
    }
    srcp += src_linesize;
}
}
