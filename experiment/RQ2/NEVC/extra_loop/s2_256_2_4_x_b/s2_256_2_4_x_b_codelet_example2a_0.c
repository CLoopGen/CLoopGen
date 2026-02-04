#include <stdio.h>

extern int b[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - 3; i += 4) {
    b[i] = x;
    b[i + 1] = -x;
    b[i + 2] = x;
    b[i + 3] = -x;
}

}
