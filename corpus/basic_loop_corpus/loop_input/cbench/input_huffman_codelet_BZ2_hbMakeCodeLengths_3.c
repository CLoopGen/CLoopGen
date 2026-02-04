#include <inttypes.h>

typedef int Int32;

Int32 alphaSize = 516;
Int32 i;
Int32 j;
Int32 weight[516];

void init_vars() {
    for (Int32 idx = 0; idx < 516; idx++) {
        weight[idx] = idx * 37;
    }
}