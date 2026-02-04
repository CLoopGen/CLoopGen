#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride = 1048576; // ~1MB of data
tmsize_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // since they are already initialized at file scope
}