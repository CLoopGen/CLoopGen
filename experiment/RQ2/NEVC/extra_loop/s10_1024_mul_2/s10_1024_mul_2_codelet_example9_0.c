#include <stdio.h>

extern unsigned int in1[1024];
extern unsigned int in2[1024];
extern int i;
extern unsigned int output;

void loop(){
for (i = 0; i < 1024; i++) {
    output += (in1[i] * in2[i]);
}

}
