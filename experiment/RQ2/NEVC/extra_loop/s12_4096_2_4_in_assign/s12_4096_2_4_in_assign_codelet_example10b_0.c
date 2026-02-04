#include <stdio.h>

extern short *restrict in;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 4096 - 3; i += 4) {
    assign[i] = (int)in[i];
    assign[i + 1] = (int)in[i + 1];
    assign[i + 2] = (int)in[i + 2];
    assign[i + 3] = (int)in[i + 3];
}

}
