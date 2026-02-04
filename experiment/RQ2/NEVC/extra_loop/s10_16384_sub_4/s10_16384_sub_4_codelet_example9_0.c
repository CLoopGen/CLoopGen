#include <stdio.h>

extern unsigned int op1[16384];
extern unsigned int op2[16384];
extern int i;
extern unsigned int sum_sub;

void loop(){
for (i = 0; i < 16384; i++) {
    sum_sub += (op1[i] - op2[i]);
}

}
