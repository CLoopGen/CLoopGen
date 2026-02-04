#include <inttypes.h>

char work_space[84][84];
int i;
int j;

void init_vars() {
    // No additional initialization needed for the loop to run safely
    // Array bounds are within [21, 62] for both dimensions (21*3 = 63, exclusive), which is within 84
    // Variables i and j are modified in the loop, no prior initialization required
}