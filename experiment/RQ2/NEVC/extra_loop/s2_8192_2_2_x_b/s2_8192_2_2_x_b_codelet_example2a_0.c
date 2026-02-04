#include <stdio.h>

extern int b[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    b[i] = x;
    b[i + 1] = -x;
}

}
