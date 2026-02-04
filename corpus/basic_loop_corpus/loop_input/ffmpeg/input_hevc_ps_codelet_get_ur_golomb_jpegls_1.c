#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit = 1000000;
unsigned int re_index = 0;
unsigned int re_cache = 0;
unsigned int re_size_plus8 = 32;
int i = 0;

void init_vars() {
    // No dynamic allocation needed; all variables are scalar and initialized at file scope.
    // Adjusted limit to ~1e6 to achieve roughly 0.01s runtime based on typical loop behavior.
}