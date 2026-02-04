#include <stdio.h>

extern short *restrict in;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    out[i] = (int)in[i];
    out[i + 1] = (int)in[i + 1];
}

}
