#include <stdio.h>

extern int out[8192] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    out[i] = z;
}

}
