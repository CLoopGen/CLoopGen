#include <stdio.h>

extern short *restrict input1;
extern short *restrict input2;
extern short *restrict input3;
extern int *restrict ia;
extern int *restrict ib;
extern int *restrict ic;
extern int i;

void loop(){
for (i = 0; i < 64; i += 2) {
    ia[i] = (int)input1[i];
    ib[i] = (int)input2[i];
    ic[i] = (int)input3[i];
}

}
