#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 576; i += 2) {
    FLOAT8 l0 = xr_org[0][i];
    FLOAT8 r0 = xr_org[1][i];
    xr[0][i] = (l0 + r0) * (1.4142135623730951 * 0.5);
    xr[1][i] = (l0 - r0) * (1.4142135623730951 * 0.5);
    
    if (i + 1 < 576) {
        FLOAT8 l1 = xr_org[0][i+1];
        FLOAT8 r1 = xr_org[1][i+1];
        xr[0][i+1] = (l1 + r1) * (1.4142135623730951 * 0.5);
        xr[1][i+1] = (l1 - r1) * (1.4142135623730951 * 0.5);
    }
}
}
