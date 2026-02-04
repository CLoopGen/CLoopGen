#include <stdio.h>

extern short *restrict input;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    ia[i] = (int)input[i];
    ia[i + 1] = (int)input[i + 1];
    ia[i + 2] = (int)input[i + 2];
    ia[i + 3] = (int)input[i + 3];
}

}
