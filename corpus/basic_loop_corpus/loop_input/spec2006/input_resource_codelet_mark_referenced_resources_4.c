#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
struct resources *res;
int i;

void init_vars() {
    res = (struct resources *)malloc(sizeof(struct resources));
    if (!res) {
        exit(1);
    }
    memset(res, 0, sizeof(struct resources));
    for (int j = 0; j < 53; j++) {
        global_regs[j] = (j % 7 == 0); 
    }
}