#include <stdio.h>

extern unsigned int ub[512];
extern unsigned int uc[512];
extern int i;
extern unsigned int mul;

void loop(){
for (i = 0; i < 512; i++) {
    mul += (ub[i] * uc[i]);
}

}
