#include <stdio.h>

extern int a[512] __attribute__((aligned(16)));
extern int b[512] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 512 - 1; i += 2) {
    int j = a[i];
    b[i] = (j > MAX ? MAX : 0);
    b[i + 1] = j;
}

}
