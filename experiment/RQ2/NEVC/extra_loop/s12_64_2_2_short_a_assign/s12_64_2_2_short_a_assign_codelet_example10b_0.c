#include <stdio.h>

extern short *restrict short_a;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    assign[i] = (int)short_a[i];
    assign[i + 1] = (int)short_a[i + 1];
}

}
