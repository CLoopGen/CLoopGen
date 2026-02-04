#include <stdio.h>

extern int b[8192] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    b[i] = y;
}

}
