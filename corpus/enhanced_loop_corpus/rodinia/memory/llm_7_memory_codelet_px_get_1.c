#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern int size;
extern PERM *permute;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *pe = permute->pe;
    u_int temp;
    for (i = 0; i < size; i++) {
        temp = i;           // Remove direct assignment to memory
        pe[size - 1 - i] = temp; // Reverse write order: introduces WAR-like pattern across iterations
    }
}
