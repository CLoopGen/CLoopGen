#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *regmove_bb_head;
int old_max_uid;
int i;

void init_vars() {
    old_max_uid = 65536; // Size chosen to make loop take ~0.01s
    regmove_bb_head = (int*)calloc(old_max_uid + 1, sizeof(int));
}