#include <stdio.h>

extern int a[4096] __attribute__((aligned(16)));
extern int b[4096] __attribute__((aligned(16)));
extern int c[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    a[i] = b[i] * c[i];
}

}
