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
for (; i < win_l_x1; i++) {
    a[(i) * 2] -= (((i - 1) < 0 ? a[(1 + (0) * 2)] : ((i - 1) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (i - 1) * 2)])) + ((i) < 0 ? a[(1 + (0) * 2)] : ((i) >= dn ? a[(1 + (dn - 1) * 2)] : a[(1 + (i) * 2)])) + 2) >> 2;
}

}
