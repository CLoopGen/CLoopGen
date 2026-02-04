#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern short *restrict in3;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    ia[i] = (int)in1[i];
    ib[i] = (int)in2[i];
    ic[i] = (int)in3[i];
}

}
