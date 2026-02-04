#include <stdio.h>

extern int result[16384] __attribute__((aligned(16)));
extern int in1[16384] __attribute__((aligned(16)));
extern int in2[16384] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 16384 - 4; i++) {
    result[i] = in1[i + 1] - in2[i + 3];
}

}
