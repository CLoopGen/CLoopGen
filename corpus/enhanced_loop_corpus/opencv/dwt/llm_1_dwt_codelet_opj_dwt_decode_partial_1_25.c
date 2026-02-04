#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 outer_limit = (win_l_x1 + 1) / 2;
    for (OPJ_INT32 k = 0; k < outer_limit; k++) {
        OPJ_INT32 temp_i = i + k;
        if (temp_i < win_l_x1) {
            a[(temp_i) * 2] -= (((temp_i - 1) < 0 ? a[(1 + (0) * 2)] : ((temp_i - 1) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (temp_i - 1) * 2)])) + 
                                ((temp_i) < 0 ? a[(1 + (0) * 2)] : ((temp_i) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (temp_i) * 2)])) + 2) >> 2;
        }
        temp_i = i + k + outer_limit;
        if (temp_i < win_l_x1) {
            a[(temp_i) * 2] -= (((temp_i - 1) < 0 ? a[(1 + (0) * 2)] : ((temp_i - 1) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (temp_i - 1) * 2)])) + 
                                ((temp_i) < 0 ? a[(1 + (0) * 2)] : ((temp_i) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (temp_i) * 2)])) + 2) >> 2;
        }
    }
}
