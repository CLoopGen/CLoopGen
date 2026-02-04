#include <stdio.h>

extern unsigned int in1[256];
extern unsigned int in2[256];
extern int i;
extern unsigned int output;

void loop(){
for (i = 0; i < 256; i++) {
    output += (in1[i] - in2[i]);
}

}
