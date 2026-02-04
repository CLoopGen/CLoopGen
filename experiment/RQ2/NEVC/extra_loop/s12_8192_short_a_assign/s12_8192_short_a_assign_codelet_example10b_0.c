#include <stdio.h>

extern short *restrict short_a;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    assign[i] = (int)short_a[i];
}

}
