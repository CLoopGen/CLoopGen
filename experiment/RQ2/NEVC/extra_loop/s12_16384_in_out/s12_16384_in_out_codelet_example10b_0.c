#include <stdio.h>

extern short *restrict in;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    out[i] = (int)in[i];
}

}
