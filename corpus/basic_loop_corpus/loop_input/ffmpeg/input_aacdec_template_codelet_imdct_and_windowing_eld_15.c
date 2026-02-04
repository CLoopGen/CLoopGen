#include <stdlib.h>
#include <stdint.h>

int i;
int n2;

void init_vars() {
    n2 = 50000000;  // Ensures loop runs approximately 25M iterations (i += 2), targeting ~0.01 sec on modern CPU
}