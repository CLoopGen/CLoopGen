#include <stdio.h>

extern int o[64] __attribute__((aligned(16)));
extern int i1[64] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 64 - x; i++) {
    o[i] *= i1[i + x];
}

}
