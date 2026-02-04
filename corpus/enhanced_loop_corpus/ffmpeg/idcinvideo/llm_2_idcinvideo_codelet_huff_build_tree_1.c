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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 256 * 2; i += 2) {
        hnodes[i].used = 0;
        if (i + 1 < 256 * 2) {
            hnodes[i + 1].used = 0;
        }
    }
}
