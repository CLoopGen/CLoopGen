#include <inttypes.h>

int reg_set_luid[53];
unsigned int regno;
unsigned int i;
unsigned int endregno;

void init_vars() {
    regno = 0;
    endregno = 53;
}