#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

typedef struct read_result_t {
    unsigned int data1;
    unsigned int data2;
    struct read_result_t *next;
} Read_result;

typedef struct hashnode_t {
    Hash_data key;
    Read_result *results;
    struct hashnode_t *next;
} Hashnode;

extern Hashnode *node;
extern Read_result *result;
extern unsigned int search_for1;
extern unsigned int search_for2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective loop depth by unrolling the first iteration and then continuing with loop
    result = node->results;
    if (result != ((void *)0)) {
        if (result->data1 == search_for1 && (result->data2 & 1023) == search_for2)
            return;
        result = result->next;
        for (; result != ((void *)0); result = result->next) {
            if (result->data1 == search_for1 && (result->data2 & 1023) == search_for2)
                break;
        }
    }
}
