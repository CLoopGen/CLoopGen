#include <stdio.h>

extern int b[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - 1; i += 2) {
    b[i] = x;
    b[i + 1] = -x;
}

}
