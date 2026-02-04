#include <stdio.h>

extern int out[256] __attribute__((aligned(16)));
extern int in[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - x; i++) {
    out[i] = in[i + x];
}

}
