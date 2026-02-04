#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int histo_size = 131072; // Size chosen to make loop run ~0.01 seconds (adjustable based on target system)

void init_vars() {
    // Initialize variables if needed; in this case, only bounds are required
    i = 0;
}