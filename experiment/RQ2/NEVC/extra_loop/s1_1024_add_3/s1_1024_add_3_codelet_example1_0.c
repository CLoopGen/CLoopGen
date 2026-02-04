#include <stdio.h>

extern int o[1024] __attribute__((aligned(16)));
extern int i1[1024] __attribute__((aligned(16)));
extern int i2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    o[i] = i1[i] + i2[i];
}

}
