#include <stdio.h>

extern short *restrict input;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 2048; i += 2) {
    assign[i] = (int)input[i];
}

}
