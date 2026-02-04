#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[26];
    for (int i = 0; i < 26; i++) {
        indices[i] = 25 - i; // Reverse access pattern
    }
    for (x = 0; x < 26; x++) {
        Z[indices[x]] = 0;
    }
}
