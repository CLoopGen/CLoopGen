#include <stdio.h>

extern unsigned int ub[64];
extern unsigned int uc[64];
extern int i;
extern unsigned int add;

void loop(){
for (i = 0; i < 64; i++) {
    add += (ub[i] + uc[i]);
}

}
