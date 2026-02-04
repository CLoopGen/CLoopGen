#include <stdio.h>

extern short *restrict input;
extern int *restrict result;
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    result[i] = (int)input[i];
}

}
