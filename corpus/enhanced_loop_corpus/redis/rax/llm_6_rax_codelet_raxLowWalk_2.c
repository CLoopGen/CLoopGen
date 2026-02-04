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

extern unsigned char *s;
extern raxNode *h;
extern size_t i;
extern size_t j;
extern unsigned char *v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_j = 0;
    unsigned char current_s = s[i]; // Introduce local copy to remove repeated memory access (RAW dependency reduced)
    for (j = 0; j < h->size; j++) {
        temp_j = j; // Introduce WAW dependency: j is updated in loop, temp_j carries value
        if (v[temp_j] == current_s) {
            j = h->size; // Modify loop index to break early (introduces WAR: write after read on j)
        }
    }
    j = temp_j; // Final update of j reflects last value of temp_j (WAW on j)
}
