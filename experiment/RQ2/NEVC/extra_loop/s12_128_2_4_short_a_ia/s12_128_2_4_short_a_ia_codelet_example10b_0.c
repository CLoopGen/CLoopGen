#include <stdio.h>

extern short *restrict short_a;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 128 - 3; i += 4) {
    ia[i] = (int)short_a[i];
    ia[i + 1] = (int)short_a[i + 1];
    ia[i + 2] = (int)short_a[i + 2];
    ia[i + 3] = (int)short_a[i + 3];
}

}
