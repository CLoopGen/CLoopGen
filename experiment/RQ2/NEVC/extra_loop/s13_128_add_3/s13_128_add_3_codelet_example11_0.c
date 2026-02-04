#include <stdio.h>

extern int o1[128] __attribute__((aligned(16)));
extern int i1[128] __attribute__((aligned(16)));
extern int i2[128] __attribute__((aligned(16)));
extern int o2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128 / 4; i++) {
    o1[i] = i1[2 * i + 1] * i2[2 * i + 1] - i1[2 * i] * i2[2 * i];
    o2[i] = i1[2 * i] * i2[2 * i + 1] + i1[2 * i + 1] * i2[2 * i];
}

}
