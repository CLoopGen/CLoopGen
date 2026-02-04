#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

struct resources {
    char memory;
    char unch_memory;
    char volatil;
    char cc;
    HARD_REG_ELT_TYPE regs;
};

char call_used_regs[53];
char global_regs[53];
struct resources *res;
unsigned int r;

void init_vars() {
    for (unsigned int i = 0; i < 53; i++) {
        call_used_regs[i] = (i % 7 == 0);
        global_regs[i] = (i % 11 == 0);
    }
    res = malloc(sizeof(struct resources));
    if (res) {
        res->regs = 0;
    }
}