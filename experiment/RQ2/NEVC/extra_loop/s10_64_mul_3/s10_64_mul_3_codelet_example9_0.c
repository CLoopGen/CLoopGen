#include <stdio.h>

extern unsigned int ub[64];
extern unsigned int uc[64];
extern int i;
extern unsigned int result;

void loop(){
for (i = 0; i < 64; i++) {
    result += (ub[i] * uc[i]);
}

}
