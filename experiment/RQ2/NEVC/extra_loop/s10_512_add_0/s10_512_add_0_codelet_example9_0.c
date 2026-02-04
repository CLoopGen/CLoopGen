#include <stdio.h>

extern unsigned int ub[512];
extern unsigned int uc[512];
extern int i;
extern unsigned int add;

void loop(){
for (i = 0; i < 512; i++) {
    add += (ub[i] + uc[i]);
}

}
