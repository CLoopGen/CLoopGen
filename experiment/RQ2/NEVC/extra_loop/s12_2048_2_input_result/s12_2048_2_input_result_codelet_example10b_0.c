#include <stdio.h>

extern short *restrict input;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 2048; i += 2) {
    result[i] = (int)input[i];
}

}
