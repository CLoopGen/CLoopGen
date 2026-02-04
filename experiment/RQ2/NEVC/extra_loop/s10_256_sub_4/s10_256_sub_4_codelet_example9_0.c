#include <stdio.h>

extern unsigned int op1[256];
extern unsigned int op2[256];
extern int i;
extern unsigned int sum_sub;

void loop(){
for (i = 0; i < 256; i++) {
    sum_sub += (op1[i] - op2[i]);
}

}
