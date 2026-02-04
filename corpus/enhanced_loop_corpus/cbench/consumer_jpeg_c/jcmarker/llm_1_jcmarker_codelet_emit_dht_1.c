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
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 4; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 - 3 + k;
            if (idx <= 16)
                length += htbl->bits[idx];
        }
    }
}
