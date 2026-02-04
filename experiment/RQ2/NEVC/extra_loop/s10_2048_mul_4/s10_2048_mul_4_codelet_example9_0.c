#include <stdio.h>

extern unsigned int op1[2048];
extern unsigned int op2[2048];
extern int i;
extern unsigned int sum_mul;

void loop(){
for (i = 0; i < 2048; i++) {
    sum_mul += (op1[i] * op2[i]);
}

}
