#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict ia;
extern int *restrict ib;
extern int i;

void loop(){
for (i = 0; i < 4096; i += 2) {
    ia[i] = (int)in1[i];
    ib[i] = (int)in2[i];
}

}
