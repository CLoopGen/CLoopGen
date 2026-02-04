#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 576; i++) {
    int index = (i * 3) % 576; // Strided access with modulo to stay in bounds
    FLOAT8 l = xr_org[0][index];
    FLOAT8 r = xr_org[1][index];
    xr[0][index] = (l + r) * (1.4142135623730951 * 0.5);
    xr[1][index] = (l - r) * (1.4142135623730951 * 0.5);
}
}
