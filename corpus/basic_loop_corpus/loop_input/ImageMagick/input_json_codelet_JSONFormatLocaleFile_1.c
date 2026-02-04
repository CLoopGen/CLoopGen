#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *value;
char *p;
size_t length;

static char data[131072]; // 128KB of input data

void init_vars() {
    // Initialize length
    length = 0;
    
    // Populate data with mixed content to ensure diverse branch behavior
    for (size_t i = 0; i < sizeof(data) - 1; i++) {
        int r = rand() % 100;
        if (r < 5) {
            // Insert special escaped characters occasionally
            int esc = rand() % 7;
            switch (esc) {
                case 0: data[i] = '"'; break;
                case 1: data[i] = '\b'; break;
                case 2: data[i] = '\f'; break;
                case 3: data[i] = '\n'; break;
                case 4: data[i] = '\r'; break;
                case 5: data[i] = '\t'; break;
                case 6: data[i] = '\\'; break;
            }
        } else if (r < 10) {
            // Insert control characters (0-31)
            data[i] = (char)(rand() % 32);
        } else {
            // Mostly printable ASCII
            data[i] = (char)(32 + (rand() % 95));
        }
    }
    
    // Ensure null termination
    data[sizeof(data) - 1] = '\x00';
    
    // Assign value to point to data
    value = data;
    
    // Initialize p to value (will be updated in loop)
    p = value;
}