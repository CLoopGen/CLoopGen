#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int slinesizex;
extern  int slinesizey;
extern  int slinesized;
extern  int dlinesize;
extern  int intensity;
extern  int h;
extern  int w;
extern  uint16_t *spx;
extern  uint16_t *spy;
extern  uint16_t *spd;
extern uint16_t *dpd;
extern  int max;
extern  int tmin;
extern  int tmax;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int idx = 0; idx < h * w; idx++) {
    const int i = idx / w;
    const int j = idx % w;
    const int iwx = i * slinesizex;
    const int iwy = i * slinesizey;
    const int iwd = i * slinesized;
    const int x = ((spx[iwx + j]) > (max) ? (max) : (spx[iwx + j]));
    const int y = ((spy[iwy + j]) > (max) ? (max) : (spy[iwy + j]));
    const int z = spd[iwd + j];
    const int pos = y * dlinesize + x;
    if (z < tmin || z > tmax)
        continue;
    dpd[pos] = ((dpd[pos] + intensity) > (max) ? (max) : (dpd[pos] + intensity));
}
}
