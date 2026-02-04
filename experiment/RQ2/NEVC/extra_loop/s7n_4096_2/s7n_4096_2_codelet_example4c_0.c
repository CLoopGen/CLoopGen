#include <stdio.h>

extern int input[4096] __attribute__((aligned(16)));
extern int output[4096] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 4096 - 1; i += 2) {
    int j = input[i];
    output[i] = (j > MAX ? MAX : 0);
    output[i + 1] = j;
}

}
