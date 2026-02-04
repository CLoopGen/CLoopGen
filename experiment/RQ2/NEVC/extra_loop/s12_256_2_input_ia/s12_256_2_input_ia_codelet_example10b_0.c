#include <stdio.h>

extern short *restrict input;
extern int *restrict ia;
extern int i;

void loop(){
for (i = 0; i < 256; i += 2) {
    ia[i] = (int)input[i];
}

}
