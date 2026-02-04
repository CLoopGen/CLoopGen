#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;

static int clip_table_data[4] = {0, 1, 2, 3};
const int *const clip_table = clip_table_data;

void init_vars() {
    x = 0;
    y = 0;
}