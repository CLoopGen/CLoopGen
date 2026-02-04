#include <stdio.h>

extern unsigned int op1[1024];
extern unsigned int op2[1024];
extern int i;
extern unsigned int sum_add;

void loop(){
for (i = 0; i < 1024; i++) {
    sum_add += (op1[i] + op2[i]);
}

}
