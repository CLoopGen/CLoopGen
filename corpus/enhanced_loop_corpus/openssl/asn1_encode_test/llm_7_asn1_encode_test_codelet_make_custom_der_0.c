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
    unsigned char found_nonzero = 0;
    size_t temp_i = custom_data->nbytes2;
    for (i = custom_data->nbytes2; i > 0 && !found_nonzero; i--) {
        unsigned char current = custom_data->bytes2[i - 1];
        found_nonzero = (current != '\x00');
        temp_i = i - 1;
    }
    if (found_nonzero) {
        i = temp_i;
    } else {
        i = 0;
    }
}
