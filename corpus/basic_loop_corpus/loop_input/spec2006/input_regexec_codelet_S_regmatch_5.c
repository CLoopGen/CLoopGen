#include <stdio.h>
#include <inttypes.h>

typedef int I32;
typedef unsigned int U32;

I32 *PL_regendp;
U32 *PL_reglastparen;
I32 n;
I32 lastparen;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data

    static I32 regend_buffer[64 * 1024 * 1024];
    static U32 reglastparen_value = 64 * 1024 * 1024 - 1;

    PL_regendp = regend_buffer;
    PL_reglastparen = &reglastparen_value;
    lastparen = 0;
}