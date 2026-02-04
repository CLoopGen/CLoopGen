#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_regno = 1048576; // ~1M elements to target ~0.01 sec runtime

int num = 42;
int best_reg = 100;
int j;

short *reg_renumber;
int *reg_allocno;

void init_vars() {
    reg_renumber = (short*)calloc(max_regno, sizeof(short));
    reg_allocno = (int*)malloc(max_regno * sizeof(int));

    for (int i = 0; i < max_regno; i++) {
        reg_allocno[i] = (i % 100 == 0) ? num : (num + 1); // Ensure some matches
    }
}