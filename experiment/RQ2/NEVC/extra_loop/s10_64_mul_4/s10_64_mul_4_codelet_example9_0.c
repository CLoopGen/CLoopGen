#include <stdio.h>

extern unsigned int op1[64];
extern unsigned int op2[64];
extern int i;
extern unsigned int sum_mul;

void loop(){
for (i = 0; i < 64; i++) {
    sum_mul += (op1[i] * op2[i]);
}

}
