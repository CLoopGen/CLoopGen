#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t i;

void init_vars() {
    // No dynamic initialization needed for scalar variables
    // All externs are already defined at file scope and will be zero-initialized if not otherwise set
}