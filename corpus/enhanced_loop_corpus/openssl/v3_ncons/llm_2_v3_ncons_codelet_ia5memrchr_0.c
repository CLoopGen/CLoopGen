#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_IA5STRING;

extern ASN1_IA5STRING *str;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal using pointer arithmetic
    unsigned char *ptr = str->data + str->length - 1;
    for (i = str->length; i > 0 && *ptr != c; i--, ptr--)
        ;
}
