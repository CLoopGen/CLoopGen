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
    // Variant 2: Strided memory access pattern with stride of 2 nodes forward per iteration
    // Each iteration skips one additional node beyond the immediate next
    for (i = 0; i < (ssize_t)index; i++) {
        if (next != NULL && next->next != NULL) {
            next = next->next->next;
        } else {
            break; // Avoid dereferencing null pointers
        }
    }
}
