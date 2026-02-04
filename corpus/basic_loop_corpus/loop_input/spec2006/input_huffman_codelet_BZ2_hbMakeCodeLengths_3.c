#include <stdint.h>

typedef int32_t Int32;

Int32 alphaSize;
Int32 i;
Int32 j;
Int32 weight[516];

void init_vars() {
    alphaSize = 515;
    for (i = 1; i <= alphaSize; i++) {
        weight[i] = (i * 1234) % 65536;
    }
}