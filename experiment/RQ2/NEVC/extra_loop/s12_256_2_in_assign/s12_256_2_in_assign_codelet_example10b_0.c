#include <stdio.h>

extern short *restrict in;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 256; i += 2) {
    assign[i] = (int)in[i];
}

}
