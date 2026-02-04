#include <stdio.h>

extern int b[512] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 512 - 3; i += 4) {
    b[i] = y;
}

}
