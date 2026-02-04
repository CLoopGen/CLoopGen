#include <stdio.h>

extern unsigned int op1[128];
extern unsigned int op2[128];
extern int i;
extern unsigned int sum_sub;

void loop(){
for (i = 0; i < 128; i++) {
    sum_sub += (op1[i] - op2[i]);
}

}
