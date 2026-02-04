#include <stdio.h>

extern int o[512] __attribute__((aligned(16)));
extern int i1[512] __attribute__((aligned(16)));
extern int i2[512] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    o[i] = i1[i] - i2[i];
}

}
