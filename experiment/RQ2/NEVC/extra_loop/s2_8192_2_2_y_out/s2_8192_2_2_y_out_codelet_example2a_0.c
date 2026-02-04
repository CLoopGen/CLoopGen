#include <stdio.h>

extern int out[8192] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    out[i] = y;
}

}
