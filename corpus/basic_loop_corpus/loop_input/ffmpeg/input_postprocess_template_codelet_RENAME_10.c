#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int y;
int d;

static int ref_array[8][8];
static int cur_array[8][8];

int *ref_ptr = (int *)ref_array;
int *cur_ptr = (int *)cur_array;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ref_array[i][j] = rand() % 100;
            cur_array[i][j] = rand() % 100;
        }
    }
    y = 0;
    d = 0;
}