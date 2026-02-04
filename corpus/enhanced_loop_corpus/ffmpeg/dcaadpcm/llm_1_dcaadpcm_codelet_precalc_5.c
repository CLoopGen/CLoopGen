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
    int32_t t0, t1, t2, t3;
    t0 = ff_dca_adpcm_vb[i][0]; t1 = ff_dca_adpcm_vb[i][1]; t2 = ff_dca_adpcm_vb[i][2]; t3 = ff_dca_adpcm_vb[i][3];
    
    (*data)[id++] = t0 * t0;
    (*data)[id++] = 2 * t0 * t1;
    (*data)[id++] = 2 * t0 * t2;
    (*data)[id++] = 2 * t0 * t3;
    (*data)[id++] = t1 * t1;
    (*data)[id++] = 2 * t1 * t2;
    (*data)[id++] = 2 * t1 * t3;
    (*data)[id++] = t2 * t2;
    (*data)[id++] = 2 * t2 * t3;
    (*data)[id++] = t3 * t3;

    data++;
}
}
