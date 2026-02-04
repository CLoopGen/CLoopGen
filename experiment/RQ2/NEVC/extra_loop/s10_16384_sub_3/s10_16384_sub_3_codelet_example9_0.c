#include <stdio.h>

extern unsigned int ub[16384];
extern unsigned int uc[16384];
extern int i;
extern unsigned int result;

void loop(){
for (i = 0; i < 16384; i++) {
    result += (ub[i] - uc[i]);
}

}
