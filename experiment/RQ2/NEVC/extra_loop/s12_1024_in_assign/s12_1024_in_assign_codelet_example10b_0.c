#include <stdio.h>

extern short *restrict in;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    assign[i] = (int)in[i];
}

}
