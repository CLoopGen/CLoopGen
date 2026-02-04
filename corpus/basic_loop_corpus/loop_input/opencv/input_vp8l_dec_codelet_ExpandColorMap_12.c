#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int final_num_colors;

void init_vars() {
    final_num_colors = 10000000;  // 10M colors to make loop run ~0.01s
    i = 0;
}