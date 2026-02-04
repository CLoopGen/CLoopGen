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
for (i = 0; i < 4096; i += 2) {
    int id;
    int32_t t;
    const int16_t (*vb_ptr)[4] = &ff_dca_adpcm_vb[i];
    premultiplied_coeffs *dptr = data + i;
    for (int offset = 0; offset < 2 && (i + offset) < 4096; offset++) {
        id = 0;
        const int16_t *row = vb_ptr[offset];
        for (j = 0; j < 4; j++) {
            for (k = j; k < 4; k++) {
                t = (int32_t)row[j] * (int32_t)row[k];
                if (j != k)
                    t *= 2;
                (*dptr)[id++] = t;
            }
        }
        dptr++;
    }
}
}
