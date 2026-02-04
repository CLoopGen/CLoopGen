#include <stdio.h>

extern short *restrict input;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    out[i] = (int)input[i];
}

}
