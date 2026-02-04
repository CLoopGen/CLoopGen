#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int out_palette[4];
int out_alpha[4];
int i;
int selected[4];

void init_vars() {
    selected[0] = 1;
    selected[1] = 16;
    selected[2] = 17;
    selected[3] = 0;
}