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
        for (int j = 0; j < width; j++) {
            if (!((srcp[j] >> ((9 + 1) / 2)) & 1)) {
                cfine[((1 << ((9 + 1) / 2)) * ((width) * ((srcp[j]) >> ((9 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((9 + 1) / 2)) - 1)))]++;
            }
            ccoarse[((1 << ((9 + 1) / 2)) * (j) + ((srcp[j]) >> ((9 + 1) / 2)))]++;
        }
        srcp += src_linesize;
    }
}
