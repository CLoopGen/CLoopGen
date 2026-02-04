#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *px;
extern int new_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < new_size; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            px->pe[depth1] = depth1;
        }
    }
}
