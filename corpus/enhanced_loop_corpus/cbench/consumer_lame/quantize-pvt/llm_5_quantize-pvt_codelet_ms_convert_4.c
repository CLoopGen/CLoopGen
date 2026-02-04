#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int skip_next = 0;
for (i = 0; i < 576; i++) {
    FLOAT8 l = xr_org[0][i];
    FLOAT8 r = xr_org[1][i];
    if (!skip_next) {
        xr[0][i] = (l + r) * (1.4142135623730951 * 0.5);
        xr[1][i] = (l - r) * (1.4142135623730951 * 0.5);
        skip_next = (l > r) ? 1 : 0;
    } else {
        skip_next = 0;
        xr[0][i] = l * 0.7071067811865476;
        xr[1][i] = r * 0.7071067811865476;
    }
}
}
