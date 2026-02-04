#include <stdio.h>

extern unsigned int op1[512];
extern unsigned int op2[512];
extern int i;
extern unsigned int sum_add;

void loop(){
for (i = 0; i < 512; i++) {
    sum_add += (op1[i] + op2[i]);
}

}
