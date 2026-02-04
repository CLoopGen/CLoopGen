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
for (int i = 0; i < (radiusV + (jobnr != 0)) * 2; i++) {
    if (i % 2 == 0) {
        for (int j = 0; j < width; j++) {
            uint16_t val = srcp[j];
            int bucket = val >> ((9 + 1) / 2);
            ccoarse[(1 << ((9 + 1) / 2)) * j + bucket]++;
        }
    } else {
        for (int j = width - 1; j >= 0; j--) {
            uint16_t val = srcp[j];
            int offset = (1 << ((9 + 1) / 2));
            int fine_index = offset * (width * (val >> ((9 + 1) / 2)) + j) + (val & (offset - 1));
            cfine[fine_index] += 2;
        }
        srcp += src_linesize;
    }
}
}
