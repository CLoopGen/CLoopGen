#include <stdio.h>

extern unsigned int ub[4096];
extern unsigned int uc[4096];
extern int i;
extern unsigned int result;

void loop(){
for (i = 0; i < 4096; i++) {
    result += (ub[i] + uc[i]);
}

}
