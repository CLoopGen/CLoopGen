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
        int j = 0;
        for (; j < 4; j++) {
            float tmp0 = ptr[-1 - j];
            float tmp1 = ptr[j];
            ptr[-1 - j] = tmp0 * csa_table[j][0] - tmp1 * csa_table[j][1];
            ptr[j] = tmp0 * csa_table[j][1] + tmp1 * csa_table[j][0];
        }
        for (; j < 8; j++) {
            float tmp0 = ptr[-1 - j];
            float tmp1 = ptr[j];
            ptr[-1 - j] = tmp0 * csa_table[j][0] - tmp1 * csa_table[j][1];
            ptr[j] = tmp0 * csa_table[j][1] + tmp1 * csa_table[j][0];
        }
        ptr += 18;
    }
}
