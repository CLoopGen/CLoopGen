#include <stdio.h>

extern short *restrict input;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    result[i] = (int)input[i];
    result[i + 1] = (int)input[i + 1];
}

}
