#include <inttypes.h>

typedef int Int32;
typedef unsigned char Bool;

Int32 i;
Int32 runningOrder[256];
Bool bigDone[256];

void init_vars() {
    for (int j = 0; j <= 255; j++) {
        bigDone[j] = 0;
        runningOrder[j] = j;
    }
}