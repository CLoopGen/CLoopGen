#include <stdio.h>

extern int sum[8192] __attribute__((aligned(16)));
extern int in[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - x; i++) {
    sum[i] += in[i + x];
}

}
