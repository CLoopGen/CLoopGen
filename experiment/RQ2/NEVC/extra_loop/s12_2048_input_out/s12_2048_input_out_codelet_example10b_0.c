#include <stdio.h>

extern short *restrict input;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    out[i] = (int)input[i];
}

}
