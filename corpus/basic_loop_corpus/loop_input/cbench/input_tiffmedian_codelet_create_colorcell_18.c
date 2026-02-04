#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

typedef unsigned short uint16;

int red;
int green;
int blue;
int ir;
int ig;
int ib;
int i;
C_cell *ptr;
int mindist;
int tmp;
int dist;
uint16 rm[256];
uint16 gm[256];
uint16 bm[256];
int num_colors;

void init_vars() {
    red = 100;
    green = 150;
    blue = 200;
    ir = 25;
    ig = 35;
    ib = 45;
    mindist = 10000;
    num_colors = 256;

    for (int idx = 0; idx < 256; ++idx) {
        rm[idx] = (idx * 123) % 256;
        gm[idx] = (idx * 456) % 256;
        bm[idx] = (idx * 789) % 256;
    }

    ptr = (C_cell*)malloc(sizeof(C_cell));
    ptr->num_ents = 0;
}