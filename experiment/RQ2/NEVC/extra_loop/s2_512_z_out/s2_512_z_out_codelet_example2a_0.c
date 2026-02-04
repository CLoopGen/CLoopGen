#include <stdio.h>

extern int out[512] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    out[i] = z;
}

}
