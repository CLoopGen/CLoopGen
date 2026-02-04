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
    float *base_ptr = ptr;
    for (int j = 0; j < 8; j++) {
        float tmp0 = base_ptr[-1 - j];
        float tmp1 = base_ptr[j];
        float csa0 = csa_table[j][0];
        float csa1 = csa_table[j][1];
        base_ptr[-1 - j] = tmp0 * csa0 - tmp1 * csa1;
        base_ptr[j] = tmp0 * csa1 + tmp1 * csa0;
    }
    ptr += 18;
}
}
