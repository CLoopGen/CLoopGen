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
    struct partition_elem *temp = e2->next;
    for (; temp != e2; temp = temp->next) {
        temp->class_element = class_element;
        class_element++; // Introduce WAW and RAW dependency: each iteration depends on previous write to class_element
    }
}
