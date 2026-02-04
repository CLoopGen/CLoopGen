#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short **inY;
int i;
int j;
int pos_y;
int pos_x;

void init_vars() {
    const int size = 1024;
    inY = (unsigned short**)calloc(size, sizeof(unsigned short*));
    for (int idx = 0; idx < size; ++idx) {
        inY[idx] = (unsigned short*)calloc(size, sizeof(unsigned short));
    }
    pos_y = 500;
    pos_x = 500;
}