#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned char *bytes1;
    size_t nbytes1;
    unsigned char *bytes2;
    size_t nbytes2;
} TEST_CUSTOM_DATA;

extern  TEST_CUSTOM_DATA *custom_data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = custom_data->nbytes2;
    for (i = 0; i < idx; i++) {
        size_t rev_index = idx - i - 1;
        unsigned char val = custom_data->bytes2[rev_index];
        if (val != '\x00') {
            i = rev_index;
            break;
        }
    }
}
