#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int h = 1000000;
int i = 0;

void init_vars() {
    // No additional initialization needed for scalar variables
    // h is set to 1e6 to target ~0.01 sec runtime on modern CPU
}