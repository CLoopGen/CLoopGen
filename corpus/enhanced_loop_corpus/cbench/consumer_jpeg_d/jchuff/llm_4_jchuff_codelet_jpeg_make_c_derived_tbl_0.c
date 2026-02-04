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
extern int p;
extern int i;
extern int l;
extern char huffsize[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l] == 0) continue;
        for (i = 1; i <= (int)htbl->bits[l]; i++)
            huffsize[p++] = (char)l;
    }
}
