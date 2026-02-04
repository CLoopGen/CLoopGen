#include <stdio.h>

extern short *restrict in;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 16384 - 3; i += 4) {
    result[i] = (int)in[i];
    result[i + 1] = (int)in[i + 1];
    result[i + 2] = (int)in[i + 2];
    result[i + 3] = (int)in[i + 3];
}

}
