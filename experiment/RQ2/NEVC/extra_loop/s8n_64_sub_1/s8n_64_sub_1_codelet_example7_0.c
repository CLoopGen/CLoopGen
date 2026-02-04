#include <stdio.h>

extern int out[64] __attribute__((aligned(16)));
extern int in[64] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 64 - x; i++) {
    out[i] -= in[i + x];
}

}
