#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct XYRemap {
    int16_t u[4][4];
    int16_t v[4][4];
    float ker[4][4];
} XYRemap;

extern  XYRemap *rmap;
extern int16_t *u;
extern int16_t *v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 4; i++) {
        u[i] = rmap->u[(i / 2) + 1][(i % 2) + 1];
        v[i] = rmap->v[(i / 2) + 1][(i % 2) + 1];
    }
}
