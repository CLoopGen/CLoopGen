#include <stdio.h>

extern int out[4096] __attribute__((aligned(16)));
extern int in[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    out[i] = in[i + x];
}

}
