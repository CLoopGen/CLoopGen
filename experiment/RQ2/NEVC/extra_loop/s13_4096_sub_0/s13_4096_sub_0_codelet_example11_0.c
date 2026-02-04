#include <stdio.h>

extern int a[4096] __attribute__((aligned(16)));
extern int b[4096] __attribute__((aligned(16)));
extern int c[4096] __attribute__((aligned(16)));
extern int d[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096 / 4; i++) {
    a[i] = b[2 * i + 1] * c[2 * i + 1] - b[2 * i] * c[2 * i];
    d[i] = b[2 * i] * c[2 * i + 1] - b[2 * i + 1] * c[2 * i];
}

}
