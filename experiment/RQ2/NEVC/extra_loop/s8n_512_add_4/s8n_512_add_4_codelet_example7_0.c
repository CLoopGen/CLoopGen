#include <stdio.h>

extern int res[512] __attribute__((aligned(16)));
extern int in[512] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 512 - x; i++) {
    res[i] += in[i + x];
}

}
