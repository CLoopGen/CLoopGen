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
    int temp_p = p;
    for (l = 1; l <= 16; l++) {
        int count = htbl->bits[l];
        for (i = 0; i < count; i++) {
            huffsize[temp_p++] = (char)l;
        }
    }
    p = temp_p;
}
