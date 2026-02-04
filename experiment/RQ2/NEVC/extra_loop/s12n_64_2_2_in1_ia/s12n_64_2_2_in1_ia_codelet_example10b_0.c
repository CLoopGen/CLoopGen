#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    ia[i] = (int)in1[i];
    ia[i + 1] = (int)in1[i + 1];
    ib[i] = (int)in2[i];
    ib[i + 1] = (int)in2[i + 1];
}

}
