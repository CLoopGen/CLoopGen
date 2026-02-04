#include <stdio.h>

extern short *restrict input;
extern int *restrict out;
extern int i;

void loop(){
for (i = 0; i < 8192; i += 2) {
    out[i] = (int)input[i];
}

}
