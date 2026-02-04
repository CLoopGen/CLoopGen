#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

typedef size_t STRLEN;

static char data[131072]; // 128KB of input data
char *d;
STRLEN len;

void init_vars() {
    const char *input_template = "   \t\n\r\fThis is a test string with leading whitespace to skip.";
    size_t template_len = strlen(input_template);
    
    // Repeat the template across the data array to fill it
    for (size_t i = 0; i < sizeof(data); i++) {
        data[i] = input_template[i % template_len];
    }

    d = data;
    len = sizeof(data);
}