#include <stdio.h>

extern short *restrict in;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 64; i += 2) {
    result[i] = (int)in[i];
}

}
