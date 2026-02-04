#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[2][576];
extern FLOAT8 xr_org[2][576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
FLOAT8 scale = 0.7071067811865476;
for (i = 0; i < 288; i++) {
    FLOAT8 l = xr_org[0][i];
    FLOAT8 r = xr_org[1][i];
    FLOAT8 sum = l + r;
    FLOAT8 diff = l - r;
    xr[0][i] = sum * scale;
    xr[1][i] = diff * scale;
}
}
