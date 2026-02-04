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

struct resources *res;
unsigned int r;
unsigned int regno;
unsigned int last_regno;

void init_vars() {
    res = (struct resources *)calloc(1, sizeof(struct resources));
    if (!res) {
        exit(1);
    }
    regno = 0;
    last_regno = 64; // Ensures loop runs enough to take time, but avoids overflow on shift
}