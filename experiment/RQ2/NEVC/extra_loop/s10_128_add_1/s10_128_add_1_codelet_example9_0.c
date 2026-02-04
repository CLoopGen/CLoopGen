#include <stdio.h>

extern unsigned int in1[128];
extern unsigned int in2[128];
extern int i;
extern unsigned int res;

void loop(){
for (i = 0; i < 128; i++) {
    res += (in1[i] + in2[i]);
}

}
