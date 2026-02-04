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
    for (int k = 0; k < (i1 - i0) * (j1 - j0); k++) {
        i = i0 + k % (i1 - i0);
        j = j0 + k / (i1 - i0);
        if (j < j1) {
            resY_tmp[j][i] = decs->resY[j][i];
        }
    }
}
