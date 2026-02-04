#include <stdio.h>

extern int b[2048] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 2048 - 3; i += 4) {
    b[i] = z;
}

}
