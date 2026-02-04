#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  uint32_t *qmul;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on level and qmul arrays with stride of 2 (simulating access to even indices only)
    // Adjust loop bound to prevent out-of-bounds when using stride
    int j = 0;
    for (; i < total_coeff && j < total_coeff; i++, j += 2) {
        scantable--;
        int pos = *scantable;
        // Access level[j] and qmul[pos] with strided pattern on level/qmul indirectly via j
        ((int32_t *)block)[pos] = ((int)(level[j] * qmul[pos] + 32)) >> 6;
    }
}
