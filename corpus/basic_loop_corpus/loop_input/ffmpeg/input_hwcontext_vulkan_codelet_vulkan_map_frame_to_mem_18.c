#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int planes;

void init_vars() {
    planes = 1000000; // Adjusted to achieve ~0.01 sec runtime on typical modern CPU
}