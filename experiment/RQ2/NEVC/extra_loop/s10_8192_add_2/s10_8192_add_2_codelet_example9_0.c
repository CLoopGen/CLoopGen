#include <stdio.h>

extern unsigned int in1[8192];
extern unsigned int in2[8192];
extern int i;
extern unsigned int output;

void loop(){
for (i = 0; i < 8192; i++) {
    output += (in1[i] + in2[i]);
}

}
