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
    size_t j;
    for (j = custom_data->nbytes2; j > 0; j--) {
        i = j;
        if (custom_data->bytes2[i - 1] != '\x00') {
            break;
        }
    }
}
