#include <stdio.h>

extern short *restrict res2;
extern short *restrict s2;
extern short *restrict s3;
extern int *restrict res1;
extern int *restrict i2;
extern int *restrict i3;
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    res1[i] = i2[i] + i3[i];
    res2[i] = s2[i] + s3[i];
}

}
