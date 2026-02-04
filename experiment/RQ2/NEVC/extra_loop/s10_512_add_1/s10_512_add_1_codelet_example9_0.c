#include <stdio.h>

extern unsigned int in1[512];
extern unsigned int in2[512];
extern int i;
extern unsigned int res;

void loop(){
for (i = 0; i < 512; i++) {
    res += (in1[i] + in2[i]);
}

}
