#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

extern int y;

static int ref;
static int cur;

void init_vars() {
    // No dynamic initialization needed for scalar variables
    // They are already zero-initialized as static
}

// Define external variable
int y;