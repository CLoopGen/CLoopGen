#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping Array
    WORD indices[64];
    for (WORD idx = 0; idx < 64; ++idx) {
        indices[idx] = (17 * idx + 41) % 64;  // Linear congruential permutation
    }
    for (; i < 64; ++i) {
        WORD pos = indices[i];  // Use permuted index for indirect write
        if (pos >= 16) {
            WORD src1 = indices[i - 2];  // Map dependency indices as well
            WORD src2 = indices[i - 7];
            WORD src3 = indices[i - 15];
            WORD src4 = indices[i - 16];
            m[pos] = ((((m[src1]) >> 17) | (m[src1] << 15)) ^ 
                      ((m[src1] >> 19) | (m[src1] << 13)) ^ 
                      (m[src1] >> 10)) +
                     m[src2] +
                     (((m[src3] >> 7) | (m[src3] << 25)) ^ 
                      ((m[src3] >> 18) | (m[src3] << 14)) ^ 
                      (m[src3] >> 3)) +
                     m[src4];
        }
    }
}
