#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE this_insn_sets;
int regno;
int endregno;
int i;

void init_vars() {
    regno = 0;
    endregno = 64;
    this_insn_sets = 0;
}