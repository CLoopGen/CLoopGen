#include <stdio.h>

extern short *restrict input;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 128 - 3; i += 4) {
    result[i] = (int)input[i];
    result[i + 1] = (int)input[i + 1];
    result[i + 2] = (int)input[i + 2];
    result[i + 3] = (int)input[i + 3];
}

}
