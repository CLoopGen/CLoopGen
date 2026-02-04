#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *left_ch;
extern int32_t *right_ch;
extern int n;
extern int i;
extern int32_t lt;
extern int32_t rt;
extern uint64_t sum[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n - 6; i += 4) {
    int32_t vals[4][2]; // [iteration offset][0 = lt, 1 = rt]
    for (int j = 0; j < 4; j++) {
        int idx = i + j;
        vals[j][0] = left_ch[idx] - 2 * left_ch[idx - 1] + left_ch[idx - 2];
        vals[j][1] = right_ch[idx] - 2 * right_ch[idx - 1] + right_ch[idx - 2];
    }
    for (int j = 0; j < 4; j++) {
        sum[2] += (((vals[j][0] + vals[j][1]) >> 1) >= 0 ? ((vals[j][0] + vals[j][1]) >> 1) : (-((vals[j][0] + vals[j][1]) >> 1)));
        sum[3] += ((vals[j][0] - vals[j][1]) >= 0 ? (vals[j][0] - vals[j][1]) : (-(vals[j][0] - vals[j][1])));
        sum[0] += (vals[j][0] >= 0 ? vals[j][0] : -vals[j][0]);
        sum[1] += (vals[j][1] >= 0 ? vals[j][1] : -vals[j][1]);
    }
}
}
