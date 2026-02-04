#include <stdio.h>

extern int in[128] __attribute__((aligned(16)));
extern int out[128] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 128; i++) {
    int j = in[i];
    out[i] = (j > MAX ? MAX : 0);
}

}
