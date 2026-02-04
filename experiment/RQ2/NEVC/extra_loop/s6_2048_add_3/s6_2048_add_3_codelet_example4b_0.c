#include <stdio.h>

extern int o[2048] __attribute__((aligned(16)));
extern int i1[2048] __attribute__((aligned(16)));
extern int i2[2048] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 2048 - 4; i++) {
    o[i] = i1[i + 1] + i2[i + 3];
}

}
