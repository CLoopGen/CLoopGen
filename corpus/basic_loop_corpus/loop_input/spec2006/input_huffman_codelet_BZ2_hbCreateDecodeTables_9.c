#include <inttypes.h>

typedef int Int32;

Int32 *limit;
Int32 i;

static Int32 limit_array[256 * (1 << 20) / sizeof(Int32)]; // ~256MB buffer

void init_vars() {
    limit = limit_array;
    i = 0;
}