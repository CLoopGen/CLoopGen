#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t local_x;
    for (int nl = 0; nl < 100000 * 5; nl++) {
        local_x = a[0];
        for (int i = 1; i < 32000; i += 8) {
            real_t temp1 = a[i] > local_x ? a[i] : local_x;
            real_t temp2 = (i+1 < 32000 && a[i+1] > temp1) ? a[i+1] : temp1;
            real_t temp3 = (i+2 < 32000 && a[i+2] > temp2) ? a[i+2] : temp2;
            real_t temp4 = (i+3 < 32000 && a[i+3] > temp3) ? a[i+3] : temp3;
            real_t temp5 = (i+4 < 32000 && a[i+4] > temp4) ? a[i+4] : temp4;
            real_t temp6 = (i+5 < 32000 && a[i+5] > temp5) ? a[i+5] : temp5;
            real_t temp7 = (i+6 < 32000 && a[i+6] > temp6) ? a[i+6] : temp6;
            real_t temp8 = (i+7 < 32000 && a[i+7] > temp7) ? a[i+7] : temp7;
            local_x = temp8;
        }
        x = local_x;
    }
}
