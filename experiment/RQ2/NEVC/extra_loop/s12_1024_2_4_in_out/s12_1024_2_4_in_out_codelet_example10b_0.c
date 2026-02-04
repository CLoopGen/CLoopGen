#include <stdio.h>

extern short *restrict in;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 1024 - 3; i += 4) {
    out[i] = (int)in[i];
    out[i + 1] = (int)in[i + 1];
    out[i + 2] = (int)in[i + 2];
    out[i + 3] = (int)in[i + 3];
}

}
