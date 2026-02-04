#include <stdio.h>
#include <inttypes.h>

char *type;
char input_data[1048576]; // 1MB of data

void init_vars() {
    for (int i = 0; i < sizeof(input_data); i++) {
        input_data[i] = ' ';
    }
    // Null terminate to be safe, though not used in loop
    input_data[sizeof(input_data) - 1] = 'a';
    type = input_data;
}