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
    u_int *pe_local = px->pe;
    u_int size_local = px->size;
    for (i = size_local; i < new_size; i++) {
        pe_local[i] = i;
    }
}
