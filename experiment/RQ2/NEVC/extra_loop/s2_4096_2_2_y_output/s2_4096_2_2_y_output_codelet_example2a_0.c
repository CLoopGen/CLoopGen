#include <stdio.h>

extern int output[4096] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    output[i] = y;
}

}
