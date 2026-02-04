#include <stdio.h>

extern int output[64] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 64 - 1; i += 2) {
    output[i] = z;
}

}
