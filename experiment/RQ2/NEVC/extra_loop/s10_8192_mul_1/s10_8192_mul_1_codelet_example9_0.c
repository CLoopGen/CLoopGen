#include <stdio.h>

extern unsigned int in1[8192];
extern unsigned int in2[8192];
extern int i;
extern unsigned int res;

void loop(){
for (i = 0; i < 8192; i++) {
    res += (in1[i] * in2[i]);
}

}
