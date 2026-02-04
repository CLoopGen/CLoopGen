#include <stdio.h>

extern unsigned int in1[16384];
extern unsigned int in2[16384];
extern int i;
extern unsigned int res;

void loop(){
for (i = 0; i < 16384; i++) {
    res += (in1[i] + in2[i]);
}

}
