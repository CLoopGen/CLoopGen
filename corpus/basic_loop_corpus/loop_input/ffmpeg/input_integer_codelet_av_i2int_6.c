#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

AVInteger a = {{0x1234, 0x5678, 0x9ABC, 0xDEF0, 0x2468, 0xACE0, 0x1357, 0x9BDF}};
int i;
int64_t out;

void init_vars() {
    // No dynamic initialization needed; all externs are already defined at file scope
    // and initialized appropriately for safe access within loop bounds.
}