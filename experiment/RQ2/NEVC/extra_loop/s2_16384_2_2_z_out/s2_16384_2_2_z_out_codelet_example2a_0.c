#include <stdio.h>

extern int out[16384] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 16384 - 1; i += 2) {
    out[i] = z;
}

}
