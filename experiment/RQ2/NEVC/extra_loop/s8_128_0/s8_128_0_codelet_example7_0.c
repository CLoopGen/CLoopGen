#include <stdio.h>

extern int a[128] __attribute__((aligned(16)));
extern int b[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128 - x; i++) {
    a[i] = b[i + x];
}

}
