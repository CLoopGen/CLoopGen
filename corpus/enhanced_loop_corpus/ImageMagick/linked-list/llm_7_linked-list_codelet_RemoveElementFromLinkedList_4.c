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
    ElementInfo *temp_next = next;
    for (i = 1; i < (ssize_t)index; i++) {
        if (temp_next != NULL) {
            temp_next = temp_next->next;
        }
    }
    next = temp_next;
}
