#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict result1;
extern int *restrict result2;
extern int *restrict result3;
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    result1[i] = (int)short_a[i];
    result2[i] = (int)short_b[i];
    result3[i] = (int)short_c[i];
}

}
