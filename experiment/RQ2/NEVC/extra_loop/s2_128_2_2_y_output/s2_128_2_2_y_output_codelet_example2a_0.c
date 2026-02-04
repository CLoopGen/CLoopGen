#include <stdio.h>

extern int output[128] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 128 - 1; i += 2) {
    output[i] = y;
}

}
