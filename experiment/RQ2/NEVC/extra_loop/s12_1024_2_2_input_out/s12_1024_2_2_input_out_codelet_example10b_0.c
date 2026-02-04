#include <stdio.h>

extern short *restrict input;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 1024 - 1; i += 2) {
    out[i] = (int)input[i];
    out[i + 1] = (int)input[i + 1];
}

}
