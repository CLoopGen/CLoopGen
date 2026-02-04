#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int sad;
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int idx = 0; idx < 64; idx++) {
    int j = idx / 8;
    int i = idx % 8;
    sad += (((m2[j][i]) < (0) ? (-(m2[j][i])) : (m2[j][i])));
}
}
