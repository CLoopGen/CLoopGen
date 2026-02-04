#include <stdio.h>

extern int sum[4096] __attribute__((aligned(16)));
extern int in[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    sum[i] += in[i + x];
}

}
