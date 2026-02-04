#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int codesize[257];
extern int p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_p[33] = {0}; // One counter per outer loop iteration (i)
    for (i = 1; i <= 32; i++) {
        int count = 0;
        for (j = 0; j <= 255; j++) {
            if (codesize[j] == i) {
                count++;
            }
        }
        local_p[i] = count;
    }
    // Now perform the actual write using precomputed counts
    int cumulative = p;
    for (i = 1; i <= 32; i++) {
        for (j = 0; j <= 255; j++) {
            if (codesize[j] == i) {
                htbl->huffval[cumulative++] = (UINT8)j;
            }
        }
    }
    p = cumulative;
}
