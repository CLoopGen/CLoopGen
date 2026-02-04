#include <stdio.h>

extern int a[256] __attribute__((aligned(16)));
extern int b[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - x; i++) {
    a[i] = b[i + x];
}

}
