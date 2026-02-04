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
    for (i = px->size; i < new_size && px != NULL && px->pe != NULL; i++)
        if (i < px->max_size)
            px->pe[i] = i;
}
