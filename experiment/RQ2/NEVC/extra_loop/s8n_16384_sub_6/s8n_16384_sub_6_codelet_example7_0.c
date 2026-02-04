#include <stdio.h>

extern int sum[16384] __attribute__((aligned(16)));
extern int in[16384] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 16384 - x; i++) {
    sum[i] -= in[i + x];
}

}
