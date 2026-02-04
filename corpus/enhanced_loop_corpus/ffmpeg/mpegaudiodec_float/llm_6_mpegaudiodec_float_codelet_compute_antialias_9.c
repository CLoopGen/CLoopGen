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
        float tmp[8];
        float new_val1[8], new_val2[8];

        for (int j = 0; j < 8; j++) {
            tmp[j] = ptr[-1 - j];
            float tmp1 = ptr[j];
            new_val1[j] = tmp[j] * csa_table[j][0] - tmp1 * csa_table[j][1];
            new_val2[j] = tmp[j] * csa_table[j][1] + tmp1 * csa_table[j][0];
        }

        for (int j = 0; j < 8; j++) {
            ptr[-1 - j] = new_val1[j];
            ptr[j] = new_val2[j];
        }

        ptr += 18;
    }
}
