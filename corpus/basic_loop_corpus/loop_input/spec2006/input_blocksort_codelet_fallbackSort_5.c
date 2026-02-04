#include <inttypes.h>

typedef int Int32;

Int32 ftab[257];
Int32 i;

void init_vars() {
    for (int j = 0; j < 257; j++) {
        ftab[j] = j * 4;
    }
    i = 0;
}