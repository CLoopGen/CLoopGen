#include <inttypes.h>

char *t;
static char data[1048576] __attribute__((aligned(64)));

void init_vars() {
    // Initialize data with spaces and tabs at the beginning, then some non-whitespace
    for (int i = 0; i < 1048500; i++) {
        data[i] = ' ';
    }
    for (int i = 1048500; i < 1048520; i++) {
        data[i] = 'x';
    }
    // Ensure null terminator to avoid issues if treated as string
    data[1048575] = '\0';
    
    // Point t to just before a block of whitespace
    t = &data[1048490];
}

// Initialize pointer after definition
__attribute__((constructor))
static void initialize() {
    init_vars();
}