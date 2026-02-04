#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 576; i += 2) {
        for (int k = 0; k < 2 && (i + k) < 576; k++) {
            int idx = i + k;
            FLOAT8 l = xr_org[0][idx];
            FLOAT8 r = xr_org[1][idx];
            xr[0][idx] = (l + r) * (1.4142135623730951 * 0.5);
            xr[1][idx] = (l - r) * (1.4142135623730951 * 0.5);
        }
    }
}
