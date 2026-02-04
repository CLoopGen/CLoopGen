#include <stdio.h>

extern int a[16384] __attribute__((aligned(16)));
extern int b[16384] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 16384 - x; i++) {
    a[i] *= b[i + x];
}

}
