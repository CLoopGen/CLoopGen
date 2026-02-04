#include <stdio.h>

extern int in[8192] __attribute__((aligned(16)));
extern int out[8192] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 8192 - 1; i += 2) {
    int j = in[i];
    out[i] = (j > MAX ? MAX : 0);
    out[i + 1] = j;
}

}
