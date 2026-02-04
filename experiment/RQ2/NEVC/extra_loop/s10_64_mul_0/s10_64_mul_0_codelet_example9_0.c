#include <stdio.h>

extern unsigned int ub[64];
extern unsigned int uc[64];
extern int i;
extern unsigned int mul;

void loop(){
for (i = 0; i < 64; i++) {
    mul += (ub[i] * uc[i]);
}

}
