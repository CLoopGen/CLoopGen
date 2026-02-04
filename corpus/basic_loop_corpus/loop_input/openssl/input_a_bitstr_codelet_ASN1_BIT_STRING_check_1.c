#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};

typedef struct asn1_string_st ASN1_BIT_STRING;

ASN1_BIT_STRING *a;
unsigned char *flags;
int flags_len;
int i;
int ok;

void init_vars() {
    // Set data size to about 512KB for ~0.01 sec runtime estimate
    const int data_size = 512 * 1024;

    // Allocate and initialize the main structure
    a = (ASN1_BIT_STRING *)malloc(sizeof(ASN1_BIT_STRING));
    if (!a) return;

    a->length = data_size;
    a->type = 0;
    a->flags = 0;

    // Allocate and initialize data buffer
    a->data = (unsigned char *)malloc(data_size);
    if (a->data) {
        memset(a->data, 0, data_size); // Initialize to zero for predictable behavior
    }

    // Allocate and initialize flags buffer
    flags_len = data_size;
    flags = (unsigned char *)malloc(flags_len);
    if (flags) {
        memset(flags, 0, flags_len); // Initialize to zero so mask becomes 255 initially
    }

    // Initialize loop control variables
    i = 0;
    ok = 1; // Start as true to enter loop
}