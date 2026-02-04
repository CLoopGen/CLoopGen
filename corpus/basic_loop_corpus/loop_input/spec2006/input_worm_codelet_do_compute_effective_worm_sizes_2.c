#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int cw_data[421][4];
int (*cw)[4] = cw_data;
int ncw_data[421];
int *ncw = ncw_data;
int pos;
int worms[400][36];
int nworms[400];
int k;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21) ? 3 : 0;
        ncw[i] = 0;
        for (int j = 0; j < 4; j++) {
            cw_data[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 400; i++) {
        nworms[i] = i % 6;
        for (int j = 0; j < 36; j++) {
            worms[i][j] = (i + j) % 100;
        }
    }
    
    pos = 0;
    k = 0;
}