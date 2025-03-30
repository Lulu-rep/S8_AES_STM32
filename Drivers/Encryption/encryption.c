/*
 * encryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#include "encryption.h"
#include "main.h"

void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *key) {

    uint8_t state[4*4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[4*i+j] = in[i+4*j];
        }
    }
    add_round_key(state, key, 0);
    for (int round = 1; round < 10; round++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, key, round);
    }

    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, key, 10);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out[i+4*j] = state[4*i+j];
        }
    }
}

void sub_bytes(uint8_t* state){
    for(int i=0;i<4;i++){
        for(int j=0; j < 4; j++){
            state[4*i+j] = s_box[state[4*i+j]];
        }
    }
}

void shift_rows(uint8_t* state){
    uint8_t temp;
    for (int i = 1; i < 4; i++) {
        int s = 0;
        while (s < i) {
            temp = state[4*i+0];
            for (int k = 1; k < 4; k++) {
                state[4*i+k-1] = state[4*i+k];
            }
            state[4*i+4-1] = temp;
            s++;
        }
    }
}

void mix_columns(uint8_t* state) {
    uint8_t a[] = {0x02, 0x01, 0x01, 0x03};
    uint8_t col[4], res[4];
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            col[i] = state[4*i+j];
        }
        coef_mult(a, col, res);
        for (int i = 0; i < 4; i++) {
            state[4*i+j] = res[i];
        }
    }
}
