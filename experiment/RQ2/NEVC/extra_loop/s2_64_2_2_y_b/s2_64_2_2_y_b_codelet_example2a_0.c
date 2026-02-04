#include <stdio.h>

extern int b[64] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    b[i] = y;
}

}
