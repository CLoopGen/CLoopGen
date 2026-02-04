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
    int temp_p = p;
    for (i = 1; i <= 32; i++) {
        for (j = 0; j <= 255; j++) {
            if (codesize[j] == i) {
                htbl->huffval[temp_p] = (UINT8)j;
                temp_p++;
            }
        }
    }
    p = temp_p;
}
