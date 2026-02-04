#include <stdio.h>

extern int input[1024] __attribute__((aligned(16)));
extern int output[1024] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 1024; i++) {
    int j = input[i];
    output[i] = (j > MAX ? MAX : 0);
}

}
