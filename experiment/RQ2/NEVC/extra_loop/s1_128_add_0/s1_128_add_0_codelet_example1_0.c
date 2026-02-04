#include <stdio.h>

extern int a[128] __attribute__((aligned(16)));
extern int b[128] __attribute__((aligned(16)));
extern int c[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128; i++) {
    a[i] = b[i] + c[i];
}

}
