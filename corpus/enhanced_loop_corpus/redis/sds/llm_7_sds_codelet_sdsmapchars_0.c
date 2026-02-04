#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds s;
extern  char *from;
extern  char *to;
extern size_t setlen;
extern size_t j;
extern size_t i;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i;
    char *local_s_j_ptr;
    for (j = 0; j < l; j++) {
        local_s_j_ptr = &s[j];
        for (local_i = 0; local_i < setlen; local_i++) {
            if (*local_s_j_ptr == from[local_i]) {
                *local_s_j_ptr = to[local_i];
                break;
            }
        }
    }
}
