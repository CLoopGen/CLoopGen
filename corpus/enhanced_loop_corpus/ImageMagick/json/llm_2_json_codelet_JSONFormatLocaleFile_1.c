#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd character, then handle remainder)
    char *start = value;
    size_t len = 0;
    // First pass: process even indices (strided access by 2)
    for (p = start; p != NULL && *p != '\x00'; p += 2) {
        switch (*p) {
            case '"':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
            case '\\':
                {
                    if (~(length + len) < 1)
                        return;
                    len++;
                    break;
                }
            default:
                {
                    int c = (int)(unsigned char)*p;
                    if (c >= 0 && c <= 31)
                        len += 6;
                    break;
                }
        }
    }
    // Second pass: process odd indices (complete strided pattern)
    for (p = start + 1; p != NULL && *p != '\x00'; p += 2) {
        switch (*p) {
            case '"':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
            case '\\':
                {
                    if (~(length + len) < 1)
                        return;
                    len++;
                    break;
                }
            default:
                {
                    int c = (int)(unsigned char)*p;
                    if (c >= 0 && c <= 31)
                        len += 6;
                    break;
                }
        }
    }
    length += len;
}
