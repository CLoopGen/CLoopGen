#include <stdio.h>
#include <inttypes.h>

typedef struct ERR_string_data_st {
    unsigned long error;
    const char *string;
} ERR_STRING_DATA;

static char string_pool[2048];
static ERR_STRING_DATA str_array[1024];
ERR_STRING_DATA *str = str_array;
unsigned long plib = 0x80000000UL;

void init_vars() {
    for (int i = 0; i < 1023; i++) {
        str_array[i].error = (unsigned long)(i + 1) * 17;
        str_array[i].string = &string_pool[i % sizeof(string_pool)];
    }
    str_array[1023].error = 0;
    str_array[1023].string = &string_pool[1023 % sizeof(string_pool)];
    plib = 0x80000000UL;
    str = str_array;
}