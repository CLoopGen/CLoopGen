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
    size_t step = 2;
    size_t limit = (custom_data->nbytes2 + step - 1) / step;
    for (i = limit; i > 0; i--) {
        size_t idx = (i * step) - 1;
        if (idx >= custom_data->nbytes2) idx = custom_data->nbytes2 - 1;
        if (custom_data->bytes2[idx] != '\x00') {
            i = idx + 1;
            break;
        }
        if (i * step - 2 < custom_data->nbytes2 && custom_data->bytes2[i * step - 2] != '\x00') {
            i = (i * step - 2) + 1;
            break;
        }
    }
    if (i == 0) i = 1;
    while (i <= custom_data->nbytes2 && custom_data->bytes2[i - 1] == '\x00') i++;
    if (i > custom_data->nbytes2) i = custom_data->nbytes2;
}
