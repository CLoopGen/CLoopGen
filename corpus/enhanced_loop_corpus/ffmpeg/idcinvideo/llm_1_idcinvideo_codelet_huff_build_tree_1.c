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
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 128; ++k) {
            int idx = j * 128 + k;
            hnodes[idx].used = 0;
        }
    }
}
