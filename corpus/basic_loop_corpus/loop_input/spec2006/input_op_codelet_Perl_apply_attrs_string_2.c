#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

char *attrstr;
STRLEN len;

static char data[1048576]; // 1MB buffer

void init_vars() {
    // Initialize data with non-whitespace characters except at the end
    memset(data, 'x', sizeof(data) - 1);
    data[sizeof(data) - 1] = ' '; // Ensure loop condition breaks here

    attrstr = data;
    len = sizeof(data);
}