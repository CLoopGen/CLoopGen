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
    for (i = n / 2; i > 0; i--) {
        float tmp0_0 = ptr[0], tmp1_0 = ptr[-1];
        float tmp0_1 = ptr[1], tmp1_1 = ptr[-2];
        float tmp0_2 = ptr[2], tmp1_2 = ptr[-3];
        float tmp0_3 = ptr[3], tmp1_3 = ptr[-4];

        ptr[-1] = tmp1_0 * csa_table[0][0] - tmp0_0 * csa_table[0][1];
        ptr[0] = tmp1_0 * csa_table[0][1] + tmp0_0 * csa_table[0][0];
        ptr[-2] = tmp1_1 * csa_table[1][0] - tmp0_1 * csa_table[1][1];
        ptr[1] = tmp1_1 * csa_table[1][1] + tmp0_1 * csa_table[1][0];
        ptr[-3] = tmp1_2 * csa_table[2][0] - tmp0_2 * csa_table[2][1];
        ptr[2] = tmp1_2 * csa_table[2][1] + tmp0_2 * csa_table[2][0];
        ptr[-4] = tmp1_3 * csa_table[3][0] - tmp0_3 * csa_table[3][1];
        ptr[3] = tmp1_3 * csa_table[3][1] + tmp0_3 * csa_table[3][0];

        ptr += 9;

        tmp0_0 = ptr[0]; tmp1_0 = ptr[-1];
        tmp0_1 = ptr[1]; tmp1_1 = ptr[-2];
        tmp0_2 = ptr[2]; tmp1_2 = ptr[-3];
        tmp0_3 = ptr[3]; tmp1_3 = ptr[-4];

        ptr[-1] = tmp1_0 * csa_table[4][0] - tmp0_0 * csa_table[4][1];
        ptr[0] = tmp1_0 * csa_table[4][1] + tmp0_0 * csa_table[4][0];
        ptr[-2] = tmp1_1 * csa_table[5][0] - tmp0_1 * csa_table[5][1];
        ptr[1] = tmp1_1 * csa_table[5][1] + tmp0_1 * csa_table[5][0];
        ptr[-3] = tmp1_2 * csa_table[6][0] - tmp0_2 * csa_table[6][1];
        ptr[2] = tmp1_2 * csa_table[6][1] + tmp0_2 * csa_table[6][0];
        ptr[-4] = tmp1_3 * csa_table[7][0] - tmp0_3 * csa_table[7][1];
        ptr[3] = tmp1_3 * csa_table[7][1] + tmp0_3 * csa_table[7][0];

        ptr += 9;
    }
}
