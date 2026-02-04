#include <stdio.h>

extern int out[4096] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 4096; i += 2) {
    out[i] = z;
}

}
