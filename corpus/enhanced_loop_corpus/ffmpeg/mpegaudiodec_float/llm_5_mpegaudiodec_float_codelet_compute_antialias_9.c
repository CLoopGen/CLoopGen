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
        float tmp0, tmp1;
        int j = 0;

        for (; j < 4; j++) {
            tmp0 = ptr[-1 - j];
            tmp1 = ptr[j];
            ptr[-1 - j] = tmp0 * csa_table[j][0] - tmp1 * csa_table[j][1];
            ptr[j] = tmp0 * csa_table[j][1] + tmp1 * csa_table[j][0];
        }

        if (ptr[-1 - 7] * ptr[7] >= 0.0f) {
            for (; j < 8; j++) {
                tmp0 = ptr[-1 - j];
                tmp1 = ptr[j];
                ptr[-1 - j] = tmp0 * csa_table[j][0] - tmp1 * csa_table[j][1];
                ptr[j] = tmp0 * csa_table[j][1] + tmp1 * csa_table[j][0];
            }
        } else {
            j++;
            for (; j < 8; j++) {
                tmp0 = ptr[-1 - j];
                tmp1 = ptr[j];
                float c0 = csa_table[j][0], c1 = csa_table[j][1];
                ptr[-1 - j] = tmp0 * c0 - tmp1 * c1;
                ptr[j] = tmp0 * c1 + tmp1 * c0;
            }
        }

        ptr += 18;
    }
}
