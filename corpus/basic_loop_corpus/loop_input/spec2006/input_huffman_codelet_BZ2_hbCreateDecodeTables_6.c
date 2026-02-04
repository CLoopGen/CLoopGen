#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;

Int32 *base;
Int32 i;

static Int32 internal_base[65536]; // ~256KB data, sufficient for timing ~0.01s when combined with loop overhead

void init_vars() {
    base = internal_base;
    i = 0;
    memset(base, 0, sizeof(internal_base));
}