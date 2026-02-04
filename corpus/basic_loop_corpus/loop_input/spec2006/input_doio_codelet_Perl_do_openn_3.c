#include <stdio.h>
#include <inttypes.h>

char *type;
char data[1048576]; // 1MB of data

void init_vars() {
    for (int i = 0; i < sizeof(data) - 1; i++) {
        data[i] = ' ';
    }
    data[sizeof(data) - 1] = 'a'; // non-whitespace to break the loop
    type = data;
}