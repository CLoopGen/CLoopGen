#include <stdio.h>

extern unsigned int ub[1024];
extern unsigned int uc[1024];
extern int i;
extern unsigned int mul;

void loop(){
for (i = 0; i < 1024; i++) {
    mul += (ub[i] * uc[i]);
}

}
