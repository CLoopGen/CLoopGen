#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern short *restrict short_c;
extern int *restrict assign1;
extern int *restrict assign2;
extern int *restrict assign3;
extern int i;

void loop(){
for (i = 0; i < 256; i += 2) {
    assign1[i] = (int)short_a[i];
    assign2[i] = (int)short_b[i];
    assign3[i] = (int)short_c[i];
}

}
