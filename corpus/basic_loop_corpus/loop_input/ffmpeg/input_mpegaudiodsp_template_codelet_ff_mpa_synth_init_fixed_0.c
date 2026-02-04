#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t MPA_INT;

const int32_t ff_mpa_enwindow[257] = {0}; 

MPA_INT *window;
int i;

void init_vars() {
    window = (MPA_INT*)aligned_alloc(32, sizeof(MPA_INT) * 513);
}