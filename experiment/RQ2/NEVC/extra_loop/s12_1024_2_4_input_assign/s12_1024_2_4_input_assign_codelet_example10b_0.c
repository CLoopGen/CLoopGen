#include <stdio.h>

extern short *restrict input;
extern int *restrict assign;
extern int i;

void loop(){
for (i = 0; i < 1024 - 3; i += 4) {
    assign[i] = (int)input[i];
    assign[i + 1] = (int)input[i + 1];
    assign[i + 2] = (int)input[i + 2];
    assign[i + 3] = (int)input[i + 3];
}

}
