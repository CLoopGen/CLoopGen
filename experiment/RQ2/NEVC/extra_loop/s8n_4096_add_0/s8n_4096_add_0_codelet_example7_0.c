#include <stdio.h>

extern int a[4096] __attribute__((aligned(16)));
extern int b[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    a[i] += b[i + x];
}

}
