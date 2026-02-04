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
    for (i = i0; i < i1; i++) {
        int *resY_row = decs->resY[i0 + (i - i0)];
        int *tmp_row = resY_tmp[i - i0];
        for (j = j0; j < j1; j++) {
            tmp_row[j - j0] = resY_row[j];
        }
    }
}
