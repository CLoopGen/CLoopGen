#include <stdio.h>

extern short *restrict input;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    ia[i] = (int)input[i];
    ia[i + 1] = (int)input[i + 1];
}

}
