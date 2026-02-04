#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **inY;
unsigned short ***refY;
int i;
int j;
int ref_inx;
int pos_y;
int pos_x;

#define SIZE_Y (1 << 10)
#define SIZE_X (1 << 10)
#define REF_SIZE 10

void init_vars() {
    ref_inx = 5;
    pos_y = 100;
    pos_x = 100;

    inY = (unsigned short**)calloc(SIZE_Y, sizeof(unsigned short*));
    for (int y = 0; y < SIZE_Y; y++) {
        inY[y] = (unsigned short*)calloc(SIZE_X, sizeof(unsigned short));
    }

    refY = (unsigned short***)calloc(REF_SIZE, sizeof(unsigned short**));
    for (int r = 0; r < REF_SIZE; r++) {
        refY[r] = (unsigned short**)calloc(SIZE_Y, sizeof(unsigned short*));
        for (int y = 0; y < SIZE_Y; y++) {
            refY[r][y] = (unsigned short*)calloc(SIZE_X, sizeof(unsigned short));
            for (int x = 0; x < SIZE_X; x++) {
                refY[r][y][x] = (unsigned short)(r * 10000 + y * 100 + x);
            }
        }
    }
}