#include <stdio.h>

extern int o[128] __attribute__((aligned(16)));
extern int i1[128] __attribute__((aligned(16)));
extern int i2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128 - 4; i += 2) {
    o[i] = i1[i + 1] + i2[i + 3];
    o[i + 1] = i1[i] + i2[i + 2];
}

}
