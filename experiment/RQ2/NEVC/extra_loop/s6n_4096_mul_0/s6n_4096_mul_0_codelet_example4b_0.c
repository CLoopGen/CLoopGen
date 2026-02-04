#include <stdio.h>

extern int a[4096] __attribute__((aligned(16)));
extern int b[4096] __attribute__((aligned(16)));
extern int c[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096 - 4; i += 2) {
    a[i] = b[i + 1] * c[i + 3];
    a[i + 1] = b[i] * c[i + 2];
}

}
