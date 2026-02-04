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
    for (i = 0; i < (ssize_t)(index * 2); i++) {
        if (i % 2 == 1 && element != NULL && element->next != NULL) {
            element = element->next;
        } else if (next != NULL && element != NULL && element->next != NULL) {
            next->next = element->next;
        }
    }
}
