#include <stdio.h>

extern int out[2048] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 2048; i += 2) {
    out[i] = z;
}

}
