#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer i__1 = 20000000;  // Approximately 20 million iterations for ~0.01 sec runtime
integer j = 0;
real beta = 1.5f;
real safmin = 1.2f;

void init_vars() {
    // No dynamic initialization needed; all variables are statically initialized
}