#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t scale = 24;
int i;
int energy[5] = {1000, -2000, 3000, -4000, 5000};

void init_vars() {
    // No additional initialization needed beyond static initializers
    // Array size is fixed at 5, so loop bounds (0 to 4) are safe
    // scale is set to 24 to ensure meaningful bit shifting behavior
}