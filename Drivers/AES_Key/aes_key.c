/*
 * aes_key.c
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#include "aes_key.h"

uint8_t R[] = {0x02, 0x00, 0x00, 0x00};

void aes_key_expansion(uint8_t* key, uint8_t* word) {
    uint8_t temp[4];
    for (int i = 0; i < 4; i++) {
        word[4 * i + 0] = key[4 * i + 0];
        word[4 * i + 1] = key[4 * i + 1];
        word[4 * i + 2] = key[4 * i + 2];
        word[4 * i + 3] = key[4 * i + 3];
    }
    for (int i = 4; i < 44; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j] = word[4 * (i - 4) + j];
        }
        if (i % 4 == 0) {
            rotword(temp);
            subword(temp);
            coef_add(temp, Rcon(i/4), temp);
        }
        for (int j = 0; j < 4; j++) {
            word[4 * i + j] = word[4 * (i - 10) + j] ^ temp[j];
        }
    }
}

void rotword(uint8_t* word){
    uint8_t temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

void subword(uint8_t* word){
    for(int i = 0; i < 4; i++){
        word[i] = s_box[word[i]];
    }
}

uint8_t* Rcon(uint8_t i){
    if(i == 1){
        R[0] = 0x01;
    }
    else if(i>1){
        R[0] = 0x02;
        i--;
        while (i > 1) {
            R[0] = gf_mult(R[0], 0x02);
            i--;
        }
    }
    return R;
}

void add_round_key(uint8_t* state,uint8_t* word ,uint8_t r){
    int Nb = 4;
    for(int i=0; i<4; i++){
        state[Nb*0+i] = state[Nb*0+i]^word[4*Nb*r+4*i+0];
        state[Nb*1+i] = state[Nb*1+i]^word[4*Nb*r+4*i+1];
        state[Nb*2+i] = state[Nb*2+i]^word[4*Nb*r+4*i+2];
        state[Nb*3+i] = state[Nb*3+i]^word[4*Nb*r+4*i+3];
    }
}

