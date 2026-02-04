#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
        int idx1 = 8 * (2*j + 0) + i;
        int idx2 = 8 * (2*j + 1) + i;
        int a = temp[idx1];
        int b = temp[idx2];
        temp[idx1] = a + b;
        temp[idx2] = a - b;
    }
    for (int j = 0; j < 2; j++) {
        int idx1 = 8 * (2*j + 0) + i;
        int idx2 = 8 * (2*j + 2) + i;
        int a = temp[idx1];
        int b = temp[idx2];
        temp[idx1] = a + b;
        temp[idx2] = a - b;
    }
    int t0 = temp[8*0+i], t1 = temp[8*1+i], t2 = temp[8*2+i], t3 = temp[8*3+i];
    int t4 = temp[8*4+i], t5 = temp[8*5+i], t6 = temp[8*6+i], t7 = temp[8*7+i];
    sum += (t0 + t4 > 0 ? t0 + t4 : -(t0 + t4)) + (t0 - t4 > 0 ? t0 - t4 : -(t0 - t4));
    sum += (t1 + t5 > 0 ? t1 + t5 : -(t1 + t5)) + (t1 - t5 > 0 ? t1 - t5 : -(t1 - t5));
    sum += (t2 + t6 > 0 ? t2 + t6 : -(t2 + t6)) + (t2 - t6 > 0 ? t2 - t6 : -(t2 - t6));
    sum += (t3 + t7 > 0 ? t3 + t7 : -(t3 + t7)) + (t3 - t7 > 0 ? t3 - t7 : -(t3 - t7));
}

}
