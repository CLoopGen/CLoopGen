#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

struct resources {
    char memory;
    char unch_memory;
    char volatil;
    char cc;
    HARD_REG_ELT_TYPE regs;
};

char global_regs[53];
struct resources end_of_function_needs;
int i;

void init_vars() {
    for (int j = 0; j < 53; j++) {
        global_regs[j] = (j % 7 == 0) ? 1 : 0;
    }
    end_of_function_needs.memory = 0;
    end_of_function_needs.unch_memory = 0;
    end_of_function_needs.volatil = 0;
    end_of_function_needs.cc = 0;
    end_of_function_needs.regs = 0;
    i = 0;
}