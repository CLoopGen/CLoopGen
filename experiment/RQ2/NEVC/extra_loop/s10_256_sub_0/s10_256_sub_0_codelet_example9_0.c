#include <stdio.h>

extern unsigned int ub[256];
extern unsigned int uc[256];
extern int i;
extern unsigned int sub;

void loop(){
for (i = 0; i < 256; i++) {
    sub += (ub[i] - uc[i]);
}

}
