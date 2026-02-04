#include <stdio.h>

extern int out[256] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 256 - 3; i += 4) {
    out[i] = y;
}

}
