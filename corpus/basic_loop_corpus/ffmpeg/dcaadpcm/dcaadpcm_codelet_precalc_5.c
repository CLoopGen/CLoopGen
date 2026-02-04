#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t premultiplied_coeffs[10];

extern const int16_t ff_dca_adpcm_vb[4096][4];
extern premultiplied_coeffs *data;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4096; i++) {
    int id = 0;
    int32_t t = 0;
    for (j = 0; j < 4; j++) {
        for (k = j; k < 4; k++) {
            t = (int32_t)ff_dca_adpcm_vb[i][j] * (int32_t)ff_dca_adpcm_vb[i][k];
            if (j != k)
                t *= 2;
            (*data)[id++] = t;
        }
    }
    data++;
}

}
