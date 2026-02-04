#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[576];
extern int i;
extern int j;
extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, j = 0; j < 96; j++) {
    for (b = 0; b < 6; b++) {
        en[b % 3] += xr[i] * xr[i] + xr[i] * 0.5;
        i++;
    }
}
}
