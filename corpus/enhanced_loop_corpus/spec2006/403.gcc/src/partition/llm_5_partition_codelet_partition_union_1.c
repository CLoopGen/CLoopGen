#include <stdio.h>

#include <inttypes.h>

struct partition_elem {
    int class_element;
    struct partition_elem *next;
    unsigned int class_count;
};


extern struct partition_elem *e2;
extern struct partition_elem *p;
extern int class_element;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = e2->next; p != e2; p = p->next) {
        if (p->class_element == class_element) {
            continue;
        }
        p->class_element = class_element;
    }
}
