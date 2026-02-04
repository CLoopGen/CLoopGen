#include <stdio.h>

extern int res[256] __attribute__((aligned(16)));
extern int in[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - x; i++) {
    res[i] += in[i + x];
}

}
