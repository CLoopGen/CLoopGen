#include <stdio.h>

extern int input[256] __attribute__((aligned(16)));
extern int result[256] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 256; i++) {
    int j = input[i];
    result[i] = (j > MAX ? MAX : 0);
}

}
