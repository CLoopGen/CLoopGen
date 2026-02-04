#include <stdio.h>

extern int a[256] __attribute__((aligned(16)));
extern int b[256] __attribute__((aligned(16)));
extern int c[256] __attribute__((aligned(16)));
extern int d[256] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 256 / 4; i++) {
    a[i] = b[2 * i + 1] * c[2 * i + 1] - b[2 * i] * c[2 * i];
    d[i] = b[2 * i] * c[2 * i + 1] + b[2 * i + 1] * c[2 * i];
}

}
