#include <stdio.h>

extern short *restrict short1;
extern short *restrict short2;
extern short *restrict short3;
extern int *restrict int1;
extern int *restrict int2;
extern int *restrict int3;
extern int i;

void loop(){
for (i = 0; i < 64; i++) {
    int1[i] = int2[i] + int3[i];
    short1[i] = short2[i] + short3[i];
}

}
