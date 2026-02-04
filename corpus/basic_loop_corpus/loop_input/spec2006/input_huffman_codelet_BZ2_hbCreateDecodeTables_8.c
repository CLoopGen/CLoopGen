#include <inttypes.h>

typedef int Int32;

Int32 *base;
Int32 i;

static Int32 data[65536];

void init_vars() {
    base = data;
    i = 0;
    for (int j = 0; j < 65536; j++) {
        data[j] = 1;
    }
}