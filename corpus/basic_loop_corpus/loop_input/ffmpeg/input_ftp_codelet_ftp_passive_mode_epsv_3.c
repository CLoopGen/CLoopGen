#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *res;
char *start;
char *end;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    // Allocate buffer with large size to ensure loop runs for noticeable time
    res = (char*)malloc(DATA_SIZE);
    if (!res) {
        exit(1);
    }
    
    // Initialize most of the buffer with regular characters
    memset(res, 'a', DATA_SIZE - 1);
    
    // Place '(' near the beginning to set start pointer
    res[100] = '(';
    
    // Place ')' much later to force loop to iterate through large portion of data
    res[DATA_SIZE - 2] = ')';
    
    // Null terminate the string so loop condition works
    res[DATA_SIZE - 1] = '\0';
    
    // Initialize other pointers to NULL to ensure clean state
    start = NULL;
    end = NULL;
    i = 0;
}