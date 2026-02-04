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
    if (index <= 1) return;
    ssize_t step = 2;
    for (i = 1; i < (ssize_t)index; i += step) {
        if (next != NULL) next = next->next;
        if (next != NULL && i + 1 < (ssize_t)index) next = next->next;
    }
}
