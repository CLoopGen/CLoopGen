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
    volatile uint64_t temp;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp = i * j + 2; // Eliminate any meaningful data dependency; all operations are independent
            temp += j > 0 ? temp : 0; // Break WAW and WAR hazards by making each iteration self-contained
        }
    }
}
