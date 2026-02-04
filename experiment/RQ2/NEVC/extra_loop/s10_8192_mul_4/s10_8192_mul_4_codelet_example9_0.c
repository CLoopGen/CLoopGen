#include <stdio.h>

extern unsigned int op1[8192];
extern unsigned int op2[8192];
extern int i;
extern unsigned int sum_mul;

void loop(){
for (i = 0; i < 8192; i++) {
    sum_mul += (op1[i] * op2[i]);
}

}
