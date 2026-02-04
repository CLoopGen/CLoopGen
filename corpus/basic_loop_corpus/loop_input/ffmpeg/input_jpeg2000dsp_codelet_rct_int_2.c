#include <stdlib.h>
#include <stdint.h>

int csize;
int32_t *src0;
int32_t *src1;
int32_t *src2;
int32_t i0;
int32_t i1;
int32_t i2;
int i;

void init_vars() {
    // Allocate approximately 64MB of total data to target ~0.01s runtime
    // Use 3 arrays of ~21M elements (3 * 21M * 4 = ~252MB)
    // Adjusted down to stay within typical L3 but still measurable
    csize = 1 << 20; // 1 million elements per array

    src0 = (int32_t*)aligned_alloc(32, csize * sizeof(int32_t));
    src1 = (int32_t*)aligned_alloc(32, csize * sizeof(int32_t));
    src2 = (int32_t*)aligned_alloc(32, csize * sizeof(int32_t));

    for (int j = 0; j < csize; j++) {
        src0[j] = (int32_t)(j * 3 + 1);
        src1[j] = (int32_t)(j * 2 + 2);
        src2[j] = (int32_t)(j * 1 + 3);
    }

    i0 = 0;
    i1 = 0;
    i2 = 0;
    i = 0;
}