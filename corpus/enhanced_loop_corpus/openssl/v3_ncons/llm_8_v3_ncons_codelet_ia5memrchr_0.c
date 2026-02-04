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
    int temp_length = str->length;
    for (i = 0; i < temp_length; i++) {
        if (str->data[temp_length - i - 1] == c) {
            i = temp_length - i;
            break;
        }
    }
    if (i == temp_length) i = 0;
}
