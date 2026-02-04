#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

typedef struct {
    int **resY;
    unsigned short ***decY;
    unsigned short ****decref;
    unsigned short ***decY_best;
    unsigned short **RefBlock;
    byte **status_map;
    byte **dec_mb_mode;
} Decoders;

extern Decoders *decs;
extern int i;
extern int j;
extern int resY_tmp[16][16];
extern int i0;
extern int i1;
extern int _usr_j0;
extern int _usr_j1;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    int stride = 2;
    for (i = i0; i < i1; i += stride)
        for (j = j0; j < j1; j += stride) {
            resY_tmp[j][i] = decs->resY[j][i];
            if (i + 1 < i1) resY_tmp[j][i+1] = decs->resY[j][i+1];
            if (j + 1 < j1) resY_tmp[j+1][i] = decs->resY[j+1][i];
            if (i + 1 < i1 && j + 1 < j1) resY_tmp[j+1][i+1] = decs->resY[j+1][i+1];
        }
}
