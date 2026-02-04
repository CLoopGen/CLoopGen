#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *p;
int64_t offset;
int in_brackets;

static char data[131072]; // 128KB of input data

void init_vars() {
    const char *sample = 
        "    \t\t    [this:is.a-test123] followed by more [nested:inside] and ] ignored chars ]]]]";
    
    size_t sample_len = strlen(sample);
    size_t repeat_count = sizeof(data) / sample_len;
    
    char *ptr = data;
    for (size_t i = 0; i < repeat_count; i++) {
        memcpy(ptr, sample, sample_len);
        ptr += sample_len;
    }
    // Fill any leftover space
    size_t remainder = sizeof(data) - (ptr - data);
    if (remainder > 0) {
        memcpy(ptr, sample, remainder);
    }

    p = data;
    offset = 0;
    in_brackets = 0;

    // Simulate some initial state to ensure meaningful execution
    // Advance a bit into the data so we have work to do
    offset = 5; // Start past initial whitespace
    in_brackets = 1; // Simulate being inside brackets
}