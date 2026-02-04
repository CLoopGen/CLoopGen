#include <stdio.h>

extern int output[16384] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 16384 - 3; i += 4) {
    output[i] = z;
}

}
