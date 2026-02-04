#include <stdio.h>

extern int a[1024] __attribute__((aligned(16)));
extern int b[1024] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 1024; i++) {
    int j = a[i];
    b[i] = (j > MAX ? MAX : 0);
}

}
