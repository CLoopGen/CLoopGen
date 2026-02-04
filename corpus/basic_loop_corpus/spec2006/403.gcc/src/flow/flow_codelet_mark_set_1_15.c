#include <stdio.h>

#include <inttypes.h>

extern int regno_first;
extern int regno_last;
extern int i;
extern char regs_ever_live[53];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = regno_first; i <= regno_last; i++)
    regs_ever_live[i] = 1;

}
