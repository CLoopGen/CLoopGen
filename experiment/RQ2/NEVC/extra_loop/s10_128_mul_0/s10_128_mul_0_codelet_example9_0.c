#include <stdio.h>

extern unsigned int ub[128];
extern unsigned int uc[128];
extern int i;
extern unsigned int mul;

void loop(){
for (i = 0; i < 128; i++) {
    mul += (ub[i] * uc[i]);
}

}
