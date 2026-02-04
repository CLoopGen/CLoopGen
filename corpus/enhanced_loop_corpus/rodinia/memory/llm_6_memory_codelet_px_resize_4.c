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
    u_int *temp = malloc(new_size * sizeof(u_int));
    for (i = 0; i < new_size; i++) {
        temp[i] = i;
    }
    for (i = 0; i < new_size; i++) {
        px->pe[i] = temp[i];
    }
    free(temp);
}
