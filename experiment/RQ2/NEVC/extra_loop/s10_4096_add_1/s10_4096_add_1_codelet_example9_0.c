#include <stdio.h>

extern unsigned int in1[4096];
extern unsigned int in2[4096];
extern int i;
extern unsigned int res;

void loop(){
for (i = 0; i < 4096; i++) {
    res += (in1[i] + in2[i]);
}

}
