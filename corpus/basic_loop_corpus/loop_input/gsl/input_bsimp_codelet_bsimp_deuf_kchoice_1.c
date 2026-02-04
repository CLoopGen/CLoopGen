#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int bd_sequence[8] = {1, 2, 3, 4, 5, 6, 7, 8};
double a_work[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int k = 0;

void init_vars() {
    // No dynamic allocation needed; static arrays are already initialized
    // Ensure initial conditions satisfy loop constraints
    a_work[0] = 10.5;
    for (int i = 0; i < 8; i++) {
        bd_sequence[i] = (i + 1) * 10;
    }
}