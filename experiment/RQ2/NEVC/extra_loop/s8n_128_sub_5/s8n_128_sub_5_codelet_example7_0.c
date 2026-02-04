#include <stdio.h>

extern int o[128] __attribute__((aligned(16)));
extern int i1[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128 - x; i++) {
    o[i] -= i1[i + x];
}

}
