#include <inttypes.h>

typedef int Int32;

Int32 alphaSize = 256;
Int32 nHeap = 0;
Int32 i = 0;
Int32 heap[260];
Int32 weight[516];
Int32 parent[516];

void init_vars() {
    for (Int32 idx = 0; idx < 516; idx++) {
        weight[idx] = (idx < 1) ? 0 : (512 - idx) * 17 + 1;
    }
    for (Int32 idx = 0; idx < 516; idx++) {
        parent[idx] = -2;
    }
    for (Int32 idx = 0; idx < 260; idx++) {
        heap[idx] = 0;
    }
    nHeap = 0;
}