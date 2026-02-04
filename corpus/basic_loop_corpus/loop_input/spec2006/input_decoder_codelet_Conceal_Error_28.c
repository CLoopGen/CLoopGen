#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **inY;
int i;
int j;
int pos_y;
int pos_x;

void init_vars() {
    const int size = 1024;
    pos_y = 0;
    pos_x = 0;

    inY = (unsigned short**)calloc(size, sizeof(unsigned short*));
    for (int y = 0; y < size; y++) {
        inY[y] = (unsigned short*)calloc(size, sizeof(unsigned short));
    }
}