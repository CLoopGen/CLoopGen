#include <stdio.h>

#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

extern AES_KEY *key;
extern u32 *rk;
extern int i;
extern int j;
extern u32 temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    u32 *start = rk;
    u32 *end = rk + 4 * (key->rounds);
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
