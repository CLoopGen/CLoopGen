#include <stdio.h>

extern int sum[128] __attribute__((aligned(16)));
extern int in[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128 - x; i++) {
    sum[i] -= in[i + x];
}

}
