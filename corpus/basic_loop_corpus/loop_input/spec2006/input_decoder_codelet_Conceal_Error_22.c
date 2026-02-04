#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short **inY;
unsigned short ***refY;
int i;
int j;
int ref_inx;
int pos_y;
int pos_x;

#define ARRAY_H 128
#define ARRAY_W 128
#define REF_COUNT 10

void init_vars() {
    ref_inx = 5;
    pos_y = 64;
    pos_x = 64;

    inY = (unsigned short**)calloc(ARRAY_H, sizeof(unsigned short*));
    for (int y = 0; y < ARRAY_H; y++) {
        inY[y] = (unsigned short*)calloc(ARRAY_W, sizeof(unsigned short));
    }

    refY = (unsigned short***)calloc(REF_COUNT, sizeof(unsigned short**));
    for (int r = 0; r < REF_COUNT; r++) {
        refY[r] = (unsigned short**)calloc(ARRAY_H, sizeof(unsigned short*));
        for (int y = 0; y < ARRAY_H; y++) {
            refY[r][y] = (unsigned short*)calloc(ARRAY_W, sizeof(unsigned short));
            for (int x = 0; x < ARRAY_W; x++) {
                refY[r][y][x] = (unsigned short)(r * 1000 + y * ARRAY_W + x);
            }
        }
    }
}