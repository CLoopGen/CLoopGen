#include <stdio.h>
#include <inttypes.h>

int mark[7056];
int ii;

void init_vars() {
    // The array mark is of size 7056, which matches the loop bound: 21 * 4 * 21 * 4 = 7056
    // No additional initialization needed beyond ensuring array is defined
    // The loop will assign mark[ii] = 1 for all indices from 0 to 7055
}