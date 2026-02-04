#include <stdio.h>

extern short *restrict in;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 64 - 3; i += 4) {
    ia[i] = (int)in[i];
    ia[i + 1] = (int)in[i + 1];
    ia[i + 2] = (int)in[i + 2];
    ia[i + 3] = (int)in[i + 3];
}

}
