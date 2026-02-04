#include <stdio.h>

extern int a[8192] __attribute__((aligned(16)));
extern int b[8192] __attribute__((aligned(16)));
extern int c[8192] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    a[i] = b[i] + c[i];
}

}
