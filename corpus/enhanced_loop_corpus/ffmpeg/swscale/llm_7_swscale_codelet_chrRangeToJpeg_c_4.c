#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dstU;
extern int16_t *dstV;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i += 2) {
        int16_t valU1 = (dstU[i] > 30775) ? 30775 : dstU[i];
        int16_t valV1 = (dstV[i] > 30775) ? 30775 : dstV[i];
        int16_t resU1 = ((valU1 * 4663 - 9289992) >> 12);
        int16_t resV1 = ((valV1 * 4663 - 9289992) >> 12);

        if (i + 1 < width) {
            int16_t valU2 = (dstU[i+1] > 30775) ? 30775 : dstU[i+1];
            int16_t valV2 = (dstV[i+1] > 30775) ? 30775 : dstV[i+1];
            int16_t resU2 = ((valU2 * 4663 - 9289992) >> 12);
            int16_t resV2 = ((valV2 * 4663 - 9289992) >> 12);

            // Introduce artificial WAW and RAW dependencies by reordering and reusing results
            dstU[i]   = resU1;
            dstV[i]   = resV1;
            dstU[i+1] = resU2;
            dstV[i+1] = resV2;
        } else {
            dstU[i] = resU1;
            dstV[i] = resV1;
        }
    }
}
