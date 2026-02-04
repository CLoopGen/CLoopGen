#include <stdio.h>

extern int out[8192] __attribute__((aligned(16)));
extern int in[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - x; i++) {
    out[i] += in[i + x];
}

}
