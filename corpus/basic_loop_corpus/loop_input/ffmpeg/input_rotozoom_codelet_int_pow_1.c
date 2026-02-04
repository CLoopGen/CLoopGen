#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

int64_t a = 65536;
int p = (int)(0.01 * 1e9 / 2); // Approximate iterations for ~0.01 seconds (adjust based on typical CPU)
int64_t v = 1;

void init_vars() {
    // Initialize variables if needed; current values are set at declaration
    // Adjust p to control loop duration; assuming each iteration takes about 2 cycles
    if (p <= 0) p = 1;
}