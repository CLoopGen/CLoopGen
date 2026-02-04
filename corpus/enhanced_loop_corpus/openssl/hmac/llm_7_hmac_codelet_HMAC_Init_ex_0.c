#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    unsigned char temp[144];
    for (k = 0; k < 144; k++)
        temp[k] = 54 ^ keytmp[k]; // Remove direct write to pad, break WAR/WAW with intermediate array
    for (k = 0; k < 144; k++)
        pad[k] = temp[k]; // Decouple reading and writing, eliminate loop-carried dependencies
}
