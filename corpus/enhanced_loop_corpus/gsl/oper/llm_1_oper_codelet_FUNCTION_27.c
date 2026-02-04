#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M && j < N; i++) {
    j = 0;
    do {} while (++j < N && 0); // Emulates empty inner loop without using while directly in structure
}
}
