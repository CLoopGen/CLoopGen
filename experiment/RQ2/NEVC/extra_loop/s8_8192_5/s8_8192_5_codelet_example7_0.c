#include <stdio.h>

extern int o[8192] __attribute__((aligned(16)));
extern int i1[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - x; i++) {
    o[i] = i1[i + x];
}

}
