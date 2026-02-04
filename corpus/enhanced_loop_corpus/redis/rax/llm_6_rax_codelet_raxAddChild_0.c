#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct raxNode {
    uint32_t iskey : 1;
    uint32_t isnull : 1;
    uint32_t iscompr : 1;
    uint32_t size : 29;
    unsigned char data[];
} raxNode;

extern raxNode *n;
extern unsigned char c;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_pos = 0;
    uint8_t *local_data = n->data;
    uint8_t local_c = c;
    uint32_t size = n->size;
    for (pos = 0; pos < size; pos++) {
        temp_pos = pos;
        if (local_data[temp_pos] > local_c) {
            pos = temp_pos;
            break;
        }
    }
}
