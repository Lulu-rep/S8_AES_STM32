/*
 * coef_function.c
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#include "coef_function.h"

void coef_add(uint8_t a[], uint8_t b[], uint8_t result[]){
    result[0] = a[0]^b[0];
    result[1] = a[1]^b[1];
    result[2] = a[2]^b[2];
    result[3] = a[3]^b[3];
}

uint8_t gf_mult(uint8_t a, uint8_t b){
    uint8_t p=0, hsb=0;

    for(int i=0;i < 8 ; i++){
        if (b & 1){
            p ^= a;
        }
        hsb = a & 0x80;
        a <<= 1;
        if (hsb){
            a ^= 0x1b;
        }
        b >>= 1;
    }
    return p;
}
