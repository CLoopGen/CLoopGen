#include <stdio.h>

extern int o[2048] __attribute__((aligned(16)));
extern int i1[2048] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 2048 - x; i++) {
    o[i] = i1[i + x];
}

}
