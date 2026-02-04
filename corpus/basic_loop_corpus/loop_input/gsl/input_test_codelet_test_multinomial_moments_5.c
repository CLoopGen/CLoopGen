#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x_sum[10];
int k;

void init_vars() {
    // No additional initialization needed beyond defining the arrays and variables
    // since the loop itself initializes x_sum values to 0.0
    // Ensure k is used only as a loop index from 0 to 9, which is safe for x_sum[10]
}