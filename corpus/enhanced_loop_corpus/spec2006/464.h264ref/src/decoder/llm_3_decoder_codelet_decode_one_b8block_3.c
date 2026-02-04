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
    // Variant 2: Indirect memory access using pointer arithmetic to simulate indirect indexing
    // Base pointers are computed once, then accessed via offsets to reflect indirect pattern
    int *base_resY_tmp;
    int **base_decs_resY = decs->resY;
    for (i = i0; i < i1; i++) {
        for (j = j0; j < j1; j++) {
            base_resY_tmp = resY_tmp[j];  // Row base for resY_tmp
            base_resY_tmp[i] = base_decs_resY[j][i];
        }
    }
}
