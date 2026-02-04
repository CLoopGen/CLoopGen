#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride;
tmsize_t i;

void init_vars() {
    // Set stride to a value so that the loop runs for a significant duration
    // The loop runs (stride - 4) times. To achieve ~0.01 seconds, we estimate
    // that about 10 million iterations might be in the right range on modern CPUs.
    stride = 10000000 + 4;  // This gives 10M iterations
}

void loop();