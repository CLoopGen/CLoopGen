#include <stdio.h>

extern int output[8192] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 8192; i += 2) {
    output[i] = z;
}

}
