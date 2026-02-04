#include <stdio.h>

extern short *restrict short_a;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 4096 - 3; i += 4) {
    assign[i] = (int)short_a[i];
    assign[i + 1] = (int)short_a[i + 1];
    assign[i + 2] = (int)short_a[i + 2];
    assign[i + 3] = (int)short_a[i + 3];
}

}
