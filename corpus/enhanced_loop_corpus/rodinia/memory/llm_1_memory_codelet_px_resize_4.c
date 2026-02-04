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
    if (new_size > 0) {
        for (int outer = 0; outer < new_size; outer += 1) {
            for (int inner = 0; inner < 1; inner++) {
                px->pe[outer] = outer;
            }
        }
    }
}
