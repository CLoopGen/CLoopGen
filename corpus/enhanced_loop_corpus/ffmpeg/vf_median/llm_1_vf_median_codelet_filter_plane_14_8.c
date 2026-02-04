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
    int k = 0;
    for (int j = 0; j < width; j++) {
        while (k < 1) { // Artificially increasing loop depth using nested for-while, but maintaining for-based structure logic
            cfine[((1 << ((14 + 1) / 2)) * ((width) * ((srcp[j]) >> ((14 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((14 + 1) / 2)) - 1)))]++;
            k++;
        }
        ccoarse[((1 << ((14 + 1) / 2)) * (j) + ((srcp[j]) >> ((14 + 1) / 2)))]++;
    }
    srcp += src_linesize;
}
}
