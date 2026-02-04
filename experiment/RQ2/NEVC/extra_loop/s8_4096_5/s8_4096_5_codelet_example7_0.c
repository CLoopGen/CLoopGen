#include <stdio.h>

extern int o[4096] __attribute__((aligned(16)));
extern int i1[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    o[i] = i1[i + x];
}

}
