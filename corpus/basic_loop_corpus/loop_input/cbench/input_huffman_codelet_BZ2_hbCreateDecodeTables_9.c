#include <stdio.h>
#include <inttypes.h>

typedef int Int32;

Int32 *limit;
Int32 i;

static Int32 limit_array[67108864]; // ~256MB array to ensure loop runtime ~0.01s

void init_vars() {
    limit = limit_array;
    i = 0;
}