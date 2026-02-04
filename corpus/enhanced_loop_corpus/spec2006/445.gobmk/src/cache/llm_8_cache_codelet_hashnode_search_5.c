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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled condition check
    // We simulate a more compute-heavy version by duplicating the condition logic and adding redundant but safe operations
    for (result = node->results; result != ((void *)0); result = result->next) {
        unsigned int masked_data2 = result->data2 & 1023;
        unsigned int temp = masked_data2 + search_for2;  // Extra arithmetic operation
        if (result->data1 == search_for1 && masked_data2 == search_for2) {
            // Add dummy computation to increase complexity
            temp *= 2;
            temp ^= search_for1;
            if (temp == ((search_for2 << 1) ^ search_for1)) { }
            break;
        }
    }
}
