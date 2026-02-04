#include <stdio.h>

extern int sum[2048] __attribute__((aligned(16)));
extern int in[2048] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 2048 - x; i++) {
    sum[i] += in[i + x];
}

}
