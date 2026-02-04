#include <stdio.h>

extern unsigned int ub[8192];
extern unsigned int uc[8192];
extern int i;
extern unsigned int add;

void loop(){
for (i = 0; i < 8192; i++) {
    add += (ub[i] + uc[i]);
}

}
