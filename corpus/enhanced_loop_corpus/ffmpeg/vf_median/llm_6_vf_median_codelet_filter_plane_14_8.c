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
        uint16_t temp_fine = 0, temp_coarse = 0;
        for (int j = 0; j < width; j++) {
            int idx_fine = ((1 << ((14 + 1) / 2)) * ((width) * ((srcp[j]) >> ((14 + 1) / 2)) + (j)) + ((srcp[j]) & ((1 << ((14 + 1) / 2)) - 1)));
            int idx_coarse = ((1 << ((14 + 1) / 2)) * (j) + ((srcp[j]) >> ((14 + 1) / 2)));

            // Introduce temporary accumulation to create intra-loop dependency (WAW and RAW)
            temp_fine += cfine[idx_fine];
            temp_coarse += ccoarse[idx_coarse];

            cfine[idx_fine] = temp_fine;
            ccoarse[idx_coarse] = temp_coarse;

            temp_fine++; 
            temp_coarse++;
        }
        srcp += src_linesize;
    }
}
