#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int intra_pred_mode;
int candidate[3];
int i;

void init_vars() {
    intra_pred_mode = 10;
    candidate[0] = 5;
    candidate[1] = 12;
    candidate[2] = 8;
    i = 0;
}