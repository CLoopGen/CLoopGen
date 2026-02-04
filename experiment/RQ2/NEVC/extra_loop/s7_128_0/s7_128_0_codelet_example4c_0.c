#include <stdio.h>

extern int a[128] __attribute__((aligned(16)));
extern int b[128] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 128; i++) {
    int j = a[i];
    b[i] = (j > MAX ? MAX : 0);
}

}
