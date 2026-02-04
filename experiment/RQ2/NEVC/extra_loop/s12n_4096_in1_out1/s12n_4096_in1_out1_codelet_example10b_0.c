#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern int *restrict out1;
extern int *restrict out2;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    out1[i] = (int)in1[i];
    out2[i] = (int)in2[i];
}

}
