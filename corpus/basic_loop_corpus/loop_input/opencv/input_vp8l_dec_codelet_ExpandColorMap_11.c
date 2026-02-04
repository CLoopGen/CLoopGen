#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_colors = 65536;
int i;

void init_vars() {
    // Adjust num_colors to ensure loop runs for approximately desired time
    // Loop runs from i=4 to 4*num_colors - 1 => ~4 * num_colors iterations
    // Assuming simple loop body, set num_colors so that total operations take ~0.01s
    // On modern CPU, 1e8 operations ~ 0.1-0.2 seconds, so 1e7 ~ 0.01s
    // Thus set 4 * num_colors ~ 10^7 => num_colors ~ 2.5e6
    num_colors = 2500000;
}