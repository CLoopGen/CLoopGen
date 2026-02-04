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
    for (i = index > 0 ? (ssize_t)index - 1 : 0; i >= 0; i--) {
        if (next != NULL && next->next != NULL) {
            next = next->next;
        } else {
            break;
        }
    }
}
