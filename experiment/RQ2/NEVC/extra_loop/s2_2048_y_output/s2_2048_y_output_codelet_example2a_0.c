#include <stdio.h>

extern int output[2048] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    output[i] = y;
}

}
