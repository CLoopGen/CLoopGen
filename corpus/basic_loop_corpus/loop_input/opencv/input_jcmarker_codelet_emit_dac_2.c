#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char dc_in_use[16];
char ac_in_use[16];
int i;

void init_vars() {
    // No additional initialization needed beyond zero-initialization
    // as the loop itself initializes the arrays to zero.
}