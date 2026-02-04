#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int h;

void init_vars() {
    x = 1 << 25;  // Approximately 33 million iterations: h = 1, 2, 4, ..., up to just below x
                  // This should take around 0.01 seconds on a modern CPU due to loop overhead
}