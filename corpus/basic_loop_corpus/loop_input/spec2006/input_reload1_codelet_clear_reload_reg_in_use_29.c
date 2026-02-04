#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long HARD_REG_ELT_TYPE;

unsigned int start_regno = 0;
unsigned int end_regno = 64;
unsigned int r;
HARD_REG_ELT_TYPE *used_in_set;

void init_vars() {
    used_in_set = (HARD_REG_ELT_TYPE*)calloc(1, sizeof(HARD_REG_ELT_TYPE));
    if (!used_in_set) {
        exit(1);
    }
    *used_in_set = ~0UL;
    start_regno = 0;
    end_regno = sizeof(HARD_REG_ELT_TYPE) * 8; 
}