#include <stdio.h>

extern int b[128] __attribute__((aligned(16)));
extern int y;
extern int i;

void loop(){
for (i = 0; i < 128; i++) {
    b[i] = y;
}

}
