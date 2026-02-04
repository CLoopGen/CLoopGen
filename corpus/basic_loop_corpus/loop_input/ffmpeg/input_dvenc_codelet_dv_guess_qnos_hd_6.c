#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int min_qlevel[5] = {1, 2, 3, 4, 5};
int qlevels[5] = {3, 1, 4, 2, 5};
int i;
int largest = 0;

void init_vars() {
    // No dynamic allocation needed; arrays are fixed size (5 elements)
    // All variables are global and already initialized
}