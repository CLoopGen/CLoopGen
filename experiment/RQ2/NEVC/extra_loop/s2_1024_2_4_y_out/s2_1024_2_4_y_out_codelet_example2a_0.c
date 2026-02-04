#include <stdio.h>

extern int out[1024] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 1024 - 3; i += 4) {
    out[i] = y;
}

}
