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
        int threshold = width / 2;
        for (int j = 0; j < width; j++) {
            if (j >= threshold) {
                cfine[((1 << ((8 + 1) / 2)) * ((width) * ((srcp[j]) >> ((8 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((8 + 1) / 2)) - 1)))]++;
            }
            ccoarse[((1 << ((8 + 1) / 2)) * (j) + ((srcp[j]) >> ((8 + 1) / 2)))]++;
        }
        srcp += src_linesize;
    }
}
