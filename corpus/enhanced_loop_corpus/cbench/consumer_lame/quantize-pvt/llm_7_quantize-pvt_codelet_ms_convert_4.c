#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 acc_l = 0.0, acc_r = 0.0;

    for (i = 0; i < 576; i++) {
        FLOAT8 l = xr_org[0][i] + acc_l;
        FLOAT8 r = xr_org[1][i] + acc_r;

        acc_l = (l + r) * (1.4142135623730951 * 0.5);
        acc_r = (l - r) * (1.4142135623730951 * 0.5);

        xr[0][i] = acc_l;
        xr[1][i] = acc_r;
    }
}
