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
extern ElementInfo *element;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    ElementInfo *temp = element;
    ElementInfo *update_next = next;
    for (i = 1; i < (ssize_t)index; i++) {
        temp = temp->next;
        update_next = temp;
    }
    next->next = update_next->next;
}
