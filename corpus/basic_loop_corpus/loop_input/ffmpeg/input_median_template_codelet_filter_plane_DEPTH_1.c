#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;

void init_vars() {
    // Assuming typical modern CPU can handle roughly 1e8 operations per second
    // Set width to result in loop running ~0.01 seconds
    // Use 10 million iterations as a reasonable estimate for ~0.01s workload
    width = 10000000;
}