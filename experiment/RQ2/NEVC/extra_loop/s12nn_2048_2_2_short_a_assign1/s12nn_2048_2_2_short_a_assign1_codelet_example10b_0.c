#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict assign1;
extern int *restrict assign2;
extern int *restrict assign3;
extern int i;

void loop(){
for (i = 0; i < 2048 - 1; i += 2) {
    assign1[i] = (int)short_a[i];
    assign1[i + 1] = (int)short_a[i + 1];
    assign2[i] = (int)short_b[i];
    assign2[i + 1] = (int)short_b[i + 1];
    assign3[i] = (int)short_c[i];
    assign3[i + 1] = (int)short_c[i + 1];
}

}
