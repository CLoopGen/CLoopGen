#include <stdio.h>

extern unsigned int ub[16384];
extern unsigned int uc[16384];
extern int i;
extern unsigned int mul;

void loop(){
for (i = 0; i < 16384; i++) {
    mul += (ub[i] * uc[i]);
}

}
