#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp_sum[576];
    FLOAT8 temp_diff[576];

    for (i = 0; i < 576; i++) {
        temp_sum[i] = (xr_org[0][i] + xr_org[1][i]) * (1.4142135623730951 * 0.5);
        temp_diff[i] = (xr_org[0][i] - xr_org[1][i]) * (1.4142135623730951 * 0.5);
    }

    for (i = 0; i < 576; i++) {
        xr[0][i] = temp_sum[i];
        xr[1][i] = temp_diff[i];
    }
}
