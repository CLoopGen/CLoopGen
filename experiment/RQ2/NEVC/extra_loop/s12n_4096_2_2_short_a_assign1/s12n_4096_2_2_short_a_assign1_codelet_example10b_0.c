#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict assign1;
extern int *restrict assign2;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    assign1[i] = (int)short_a[i];
    assign1[i + 1] = (int)short_a[i + 1];
    assign2[i] = (int)short_b[i];
    assign2[i + 1] = (int)short_b[i + 1];
}

}
