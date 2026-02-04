#include <stdio.h>

extern int out[64] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 64; i++) {
    out[i] = z;
}

}
