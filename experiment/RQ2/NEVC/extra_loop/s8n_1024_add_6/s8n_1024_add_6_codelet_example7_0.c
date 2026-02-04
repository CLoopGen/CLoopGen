#include <stdio.h>

extern int sum[1024] __attribute__((aligned(16)));
extern int in[1024] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 1024 - x; i++) {
    sum[i] += in[i + x];
}

}
