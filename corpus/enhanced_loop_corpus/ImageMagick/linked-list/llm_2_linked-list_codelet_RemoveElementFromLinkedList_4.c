#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

extern  size_t _usr_index;
extern ElementInfo *next;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of traversing one node at a time, we skip every other node (stride of 2)
    // This modifies the access pattern to be strided, reducing total iterations by ~half
    for (i = 2; i < (ssize_t)index; i += 2) {
        if (next->next != NULL) {
            next = next->next->next;
        } else {
            break;
        }
    }
}
