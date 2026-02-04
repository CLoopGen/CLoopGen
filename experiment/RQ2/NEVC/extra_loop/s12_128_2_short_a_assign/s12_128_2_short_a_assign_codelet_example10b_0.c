#include <stdio.h>

extern short *restrict short_a;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 128; i += 2) {
    assign[i] = (int)short_a[i];
}

}
