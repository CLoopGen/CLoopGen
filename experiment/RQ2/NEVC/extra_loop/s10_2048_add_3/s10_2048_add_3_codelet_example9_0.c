#include <stdio.h>

extern unsigned int ub[2048];
extern unsigned int uc[2048];
extern int i;
extern unsigned int result;

void loop(){
for (i = 0; i < 2048; i++) {
    result += (ub[i] + uc[i]);
}

}
