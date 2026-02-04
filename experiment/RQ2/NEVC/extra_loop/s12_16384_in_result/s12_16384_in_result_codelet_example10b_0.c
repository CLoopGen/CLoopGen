#include <stdio.h>

extern short *restrict in;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    result[i] = (int)in[i];
}

}
