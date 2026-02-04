#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *regno_src_regno;
int nregs = 65536;  
int i;

void init_vars() {
    regno_src_regno = (int*)calloc(nregs, sizeof(int));
    if (!regno_src_regno) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}