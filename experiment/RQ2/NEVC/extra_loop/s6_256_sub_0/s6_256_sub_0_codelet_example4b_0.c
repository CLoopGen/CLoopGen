#include <stdio.h>

extern int a[256] __attribute__((aligned(16)));
extern int b[256] __attribute__((aligned(16)));
extern int c[256] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 256 - 4; i++) {
    a[i] = b[i + 1] - c[i + 3];
}

}
