#include <stdio.h>

extern unsigned int ub[256];
extern unsigned int uc[256];
extern int i;
extern unsigned int add;

void loop(){
for (i = 0; i < 256; i++) {
    add += (ub[i] + uc[i]);
}

}
