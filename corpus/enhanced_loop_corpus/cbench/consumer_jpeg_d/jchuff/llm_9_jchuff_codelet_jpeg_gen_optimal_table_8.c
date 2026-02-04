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
for (i = 1; i <= 64; i++) {
    int double_i = i << 1;
    for (j = 0; j < 256; j += 4) {
        int k;
        for (k = 0; k < 4 && (j + k) < 256; k++) {
            int idx = j + k;
            if (codesize[idx] == i) {
                htbl->huffval[p] = (UINT8)idx;
                p++;
            }
        }
    }
}
}
