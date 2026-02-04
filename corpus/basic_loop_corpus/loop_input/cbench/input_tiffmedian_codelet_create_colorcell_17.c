#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

typedef unsigned short uint16;

int red = 100;
int green = 150;
int blue = 200;
int ir = 25;
int ig = 30;
int ib = 35;
int i;
C_cell *ptr;
int mindist = 1000000;
int tmp;
int dist;
uint16 rm[256];
uint16 gm[256];
uint16 bm[256];
int num_colors = 256;

static C_cell _ptr_storage;

void init_vars() {
    ptr = &_ptr_storage;
    ptr->num_ents = 0;

    for (int idx = 0; idx < 256; ++idx) {
        rm[idx] = (idx * 97) % 256;
        gm[idx] = (idx * 199) % 256;
        bm[idx] = (idx * 211) % 256;
    }

    red = 100;
    green = 150;
    blue = 200;
    ir = rm[100] >> (8 - 2);
    ig = gm[100] >> (8 - 2);
    ib = bm[100] >> (8 - 2);
    mindist = 1000000;
}