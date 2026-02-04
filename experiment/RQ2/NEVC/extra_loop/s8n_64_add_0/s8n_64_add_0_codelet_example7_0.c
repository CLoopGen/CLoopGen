#include <stdio.h>

extern int a[64] __attribute__((aligned(16)));
extern int b[64] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 64 - x; i++) {
    a[i] += b[i + x];
}

}
