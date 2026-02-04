#include <stdio.h>

extern int a[2048] __attribute__((aligned(16)));
extern int b[2048] __attribute__((aligned(16)));
extern int c[2048] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    a[i] = b[i] * c[i];
}

}
