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
    size_t step = 1;
    for (i = custom_data->nbytes2; i > 0; i -= step) {
        if (custom_data->bytes2[(i - 1) * step] != '\x00')
            break;
    }
}
