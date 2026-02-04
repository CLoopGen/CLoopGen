#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t **out;
extern  int32_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    int64_t t = in[2][i] * (int64_t)coeffp[0 * 6 + 2] + in[3][i] * (int64_t)coeffp[0 * 6 + 3];
    int64_t base0 = t + in[0][i] * (int64_t)coeffp[0 * 6 + 0] + in[4][i] * (int64_t)coeffp[0 * 6 + 4];
    int64_t base1 = t + in[1][i] * (int64_t)coeffp[1 * 6 + 1] + in[5][i] * (int64_t)coeffp[1 * 6 + 5];
    int64_t corr0 = (base0 + 16384) >> 15;
    int64_t corr1 = (base1 + 16384) >> 15;
    out[0][i] = (int32_t)(corr0 < -2147483648LL ? -2147483648LL : (corr0 > 2147483647LL ? 2147483647LL : corr0));
    out[1][i] = (int32_t)(corr1 < -2147483648LL ? -2147483648LL : (corr1 > 2147483647LL ? 2147483647LL : corr1));
}
}
