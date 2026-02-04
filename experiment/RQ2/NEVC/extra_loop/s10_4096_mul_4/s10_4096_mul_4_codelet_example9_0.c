#include <stdio.h>

extern unsigned int op1[4096];
extern unsigned int op2[4096];
extern int i;
extern unsigned int sum_mul;

void loop(){
for (i = 0; i < 4096; i++) {
    sum_mul += (op1[i] * op2[i]);
}

}
