#include <stdio.h>

extern short *restrict in;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    ia[i] = (int)in[i];
    ia[i + 1] = (int)in[i + 1];
}

}
