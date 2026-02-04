#include <stdio.h>

extern short *restrict in;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 128; i += 2) {
    ia[i] = (int)in[i];
}

}
