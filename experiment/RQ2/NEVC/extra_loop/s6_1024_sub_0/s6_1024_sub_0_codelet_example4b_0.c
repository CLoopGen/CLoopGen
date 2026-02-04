#include <stdio.h>

extern int a[1024] __attribute__((aligned(16)));
extern int b[1024] __attribute__((aligned(16)));
extern int c[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024 - 4; i++) {
    a[i] = b[i + 1] - c[i + 3];
}

}
