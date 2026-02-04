#include <stdio.h>

extern short *restrict o2;
extern short *restrict i4;
extern short *restrict i5;
extern int *restrict o1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    o1[i] = i2[i] + i3[i];
    o2[i] = i4[i] + i5[i];
}

}
