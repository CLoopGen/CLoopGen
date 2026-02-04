#include <stdio.h>

extern short *restrict short_a;
extern short *restrict short_b;
extern int *restrict assign1;
extern int *restrict assign2;
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    assign1[i] = (int)short_a[i];
    assign2[i] = (int)short_b[i];
}

}
