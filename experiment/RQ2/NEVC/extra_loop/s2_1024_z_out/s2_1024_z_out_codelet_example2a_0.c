#include <stdio.h>

extern int out[1024] __attribute__((aligned(16)));
extern int z;
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    out[i] = z;
}

}
