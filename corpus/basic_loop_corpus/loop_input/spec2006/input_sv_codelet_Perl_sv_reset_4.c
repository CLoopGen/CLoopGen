#include <inttypes.h>

typedef int I32;

I32 i;
I32 max;
char todo[256];

void init_vars() {
    i = 0;
    max = 255;
    for (int j = 0; j < 256; j++) {
        todo[j] = 0;
    }
}