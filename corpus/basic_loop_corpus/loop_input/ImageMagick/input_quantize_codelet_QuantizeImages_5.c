#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t depth;
size_t colors;

void init_vars() {
    colors = (size_t)1 << 30;  // Large value to ensure loop runs for measurable time
}