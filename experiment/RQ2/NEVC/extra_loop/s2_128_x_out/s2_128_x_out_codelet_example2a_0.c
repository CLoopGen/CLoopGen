#include <stdio.h>

extern int out[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128; i++) {
    out[i] = x;
}

}
