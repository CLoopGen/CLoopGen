#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define DATA_SIZE 524288  // ~512KB input size for ~0.01 sec runtime

char *host;
size_t MAX_LABEL_LENGTH = 63;
size_t i;
int isdnsname;
size_t length;
size_t label_length;
int all_numeric;

void init_vars() {
    // Allocate host buffer
    host = (char*)malloc(DATA_SIZE);
    if (!host) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize length to be within allocated size
    length = DATA_SIZE - 64;  // Leave room for safety
    
    // Set initial state variables
    i = 0;
    label_length = 0;
    isdnsname = 1;
    all_numeric = 1;

    // Fill host with mixed DNS-like characters to exercise the loop logic
    for (size_t idx = 0; idx < length; ++idx) {
        int r = rand() % 100;
        if (r < 40) {
            host[idx] = 'a' + (rand() % 26);           // lowercase letters
        } else if (r < 50) {
            host[idx] = 'A' + (rand() % 26);           // uppercase letters
        } else if (r < 70) {
            host[idx] = '0' + (rand() % 10);           // digits
        } else if (r < 85) {
            host[idx] = '-';                           // hyphens
        } else {
            host[idx] = '.';                           // dots
        }
    }

    // Ensure no leading or trailing problematic sequences
    if (length > 0) {
        host[0] = 'a';
        host[length-1] = 'z';
    }
    // Avoid consecutive dots or dot-hyphen patterns
    for (size_t idx = 0; idx < length - 1; ++idx) {
        if (host[idx] == '.') {
            if (host[idx+1] == '.' || host[idx+1] == '-') {
                host[idx+1] = 'x';
            }
            if (idx > 0 && host[idx-1] == '-') {
                host[idx-1] = 'x';
            }
        }
    }
}