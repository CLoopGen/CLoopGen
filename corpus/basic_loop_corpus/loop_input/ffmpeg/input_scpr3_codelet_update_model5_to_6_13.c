#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int d = 1;
int e = 0;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Variables d and e are already initialized at file scope
    // The loop modifies 'd' by left-shifting until it exceeds 2048
    // Initial value of d is set to 1 to ensure the loop runs as intended
}