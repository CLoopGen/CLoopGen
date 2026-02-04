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
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if ((i + j) % 2 == 0) {
                u[i * 2 + j] = rmap->u[i + 1][j + 1];
                v[i * 2 + j] = rmap->v[i + 1][j + 1];
            } else {
                u[i * 2 + j] = 0;
                v[i * 2 + j] = 0;
            }
        }
    }
}
