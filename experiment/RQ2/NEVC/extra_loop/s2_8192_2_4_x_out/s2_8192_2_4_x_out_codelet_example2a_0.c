#include <stdio.h>

extern int out[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    out[i] = x;
    out[i + 1] = -x;
    out[i + 2] = x;
    out[i + 3] = -x;
}

}
