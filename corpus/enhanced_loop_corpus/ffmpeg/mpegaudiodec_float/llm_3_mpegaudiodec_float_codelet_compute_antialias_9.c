#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float csa_table[8][4];
extern float *ptr;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n; i > 0; i--) {
    int indices[8] = {-1, 0, -2, 1, -3, 2, -4, 3}; // Interleaved access pattern
    for (int j = 0; j < 8; j += 2) {
        int idx0 = indices[j + 0];
        int idx1 = indices[j + 1];
        float tmp0 = ptr[idx0];
        float tmp1 = ptr[idx1];
        float csa0 = csa_table[j / 2][0];
        float csa1 = csa_table[j / 2][1];
        ptr[idx0] = tmp0 * csa0 - tmp1 * csa1;
        ptr[idx1] = tmp0 * csa1 + tmp1 * csa0;
    }
    ptr += 18;
}
}
