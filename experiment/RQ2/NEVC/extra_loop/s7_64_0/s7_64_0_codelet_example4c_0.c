#include <stdio.h>

extern int a[64] __attribute__((aligned(16)));
extern int b[64] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 64; i++) {
    int j = a[i];
    b[i] = (j > MAX ? MAX : 0);
}

}
