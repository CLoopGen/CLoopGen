#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct hnode {
    int count;
    unsigned char used;
    int children[2];
} hnode;

extern hnode *hnodes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 0;
    for (i = 0; i < 256 * 2; i++) {
        hnodes[base + i].used = 0;
        base = (hnodes[i].count > 0) ? 0 : base; // Introduce RAW dependency: hnodes[i].count read after previous write
    }
}
