#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    result1[i] = (int)short_a[i];
    result1[i + 1] = (int)short_a[i + 1];
    result2[i] = (int)short_b[i];
    result2[i + 1] = (int)short_b[i + 1];
    result3[i] = (int)short_c[i];
    result3[i + 1] = (int)short_c[i + 1];
}

}
