#include <stdio.h>

extern int out[2048] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 2048; i += 2) {
    out[i] = x;
}

}
