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
        int j;

        for (j = 0; j < 8; j++) {
            if (ptr[-1 - j] != 0.0f || ptr[j] != 0.0f) {
                tmp0 = ptr[-1 - j];
                tmp1 = ptr[j];
                ptr[-1 - j] = tmp0 * csa_table[j][0] - tmp1 * csa_table[j][1];
                ptr[j] = tmp0 * csa_table[j][1] + tmp1 * csa_table[j][0];
            }
        }
        ptr += 18;
    }
}
