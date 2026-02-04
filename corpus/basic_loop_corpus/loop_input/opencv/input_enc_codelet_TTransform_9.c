#include <stdlib.h>
#include <stdint.h>

int tmp[16];
int i;

const int a0 = 5;
const int a1 = 3;
const int a2 = 2;
const int a3 = 7;

void init_vars() {
    // No dynamic initialization needed for const variables
    // All const variables are initialized at declaration
}