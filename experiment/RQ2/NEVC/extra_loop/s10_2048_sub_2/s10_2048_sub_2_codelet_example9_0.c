#include <stdio.h>

extern unsigned int in1[2048];
extern unsigned int in2[2048];
extern int i;
extern unsigned int output;

void loop(){
for (i = 0; i < 2048; i++) {
    output += (in1[i] - in2[i]);
}

}
