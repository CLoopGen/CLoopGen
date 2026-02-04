#include <stdio.h>

extern int res[4096] __attribute__((aligned(16)));
extern int in[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    res[i] *= in[i + x];
}

}
