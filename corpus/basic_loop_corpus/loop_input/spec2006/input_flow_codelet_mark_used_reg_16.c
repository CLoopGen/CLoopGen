#include <inttypes.h>

char regs_ever_live[53];
unsigned int regno_first;
unsigned int regno_last;
unsigned int i;

void init_vars() {
    regno_first = 0;
    regno_last = 52;
}