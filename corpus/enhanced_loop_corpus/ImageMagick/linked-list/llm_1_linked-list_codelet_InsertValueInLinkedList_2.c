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
    if (index > 1) {
        for (i = 1; i < (ssize_t)index; i += 2) {
            element = element->next;
            next->next = element->next;
            if (element->next != NULL) {
                element = element->next;
                if (i + 1 < (ssize_t)index) {
                    next->next = element->next;
                }
            }
        }
    }
}
