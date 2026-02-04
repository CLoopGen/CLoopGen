#include <stdio.h>

extern int in[2048] __attribute__((aligned(16)));
extern int out[2048] __attribute__((aligned(16)));
extern int i;
extern const int MAX;

void loop(){
for (i = 0; i < 2048; i++) {
    int j = in[i];
    out[i] = (j > MAX ? MAX : 0);
}

}
