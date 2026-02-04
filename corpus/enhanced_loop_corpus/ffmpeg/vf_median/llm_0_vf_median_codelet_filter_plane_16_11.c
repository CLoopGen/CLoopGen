#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < width; i++) {
            cfine[((1 << ((16 + 1) / 2)) * ((width) * ((srcp[i]) >> ((16 + 1) / 2)) + (i)) + ((srcp[i]) & ((1 << ((16 + 1) / 2)) - 1)))] += radiusV + 1;
            ccoarse[((1 << ((16 + 1) / 2)) * (i) + ((srcp[i]) >> ((16 + 1) / 2)))] += radiusV + 1;
        }
    }
}
