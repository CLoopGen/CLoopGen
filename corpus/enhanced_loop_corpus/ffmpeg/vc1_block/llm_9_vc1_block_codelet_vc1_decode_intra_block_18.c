#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_vc1_dqscale[63];
extern int16_t *ac_val2;
extern int q1;
extern int q2;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 8; k++) {
        int temp1 = ac_val2[k] * q2;
        int temp2 = temp1 * ff_vc1_dqscale[q1 - 1];
        int temp3 = temp2 + 131072;
        ac_val2[k] = (int)((unsigned int)temp3 >> 18);
    }
}
