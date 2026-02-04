#include <stdio.h>

extern int b[64] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 64 - 3; i += 4) {
    b[i] = z;
}

}
