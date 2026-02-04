#include <stdio.h>

extern int out[1024] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 1024 - 1; i += 2) {
    out[i] = x;
    out[i + 1] = -x;
}

}
