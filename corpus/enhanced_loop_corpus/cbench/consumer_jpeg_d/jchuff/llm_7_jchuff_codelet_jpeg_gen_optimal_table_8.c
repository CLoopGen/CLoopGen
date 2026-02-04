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
    int write_index[33] = {0};
    for (j = 0; j <= 255; j++) {
        int len = codesize[j];
        if (len >= 1 && len <= 32) {
            htbl->huffval[p + write_index[len]] = (UINT8)j;
            write_index[len]++;
        }
    }
    for (i = 1; i <= 32; i++) {
        p += write_index[i];
    }
}
