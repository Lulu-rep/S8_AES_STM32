/*
 * decryption.c
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#include "decryption.h"
#include "main.h"
#define Nb 4

void InvCipher(uint8_t* state,int num_rounds,uint8_t* RoundKey){

}

void InvShftRows(uint8_t* state){
	uint8_t i, k, s, tmp;

	for (i = 1; i < 4; i++) {
		s = 0;
		while (s < i) {
			tmp = state[Nb*i+Nb-1];

			for (k = Nb-1; k > 0; k--) {
				state[Nb*i+k] = state[Nb*i+k-1];
			}

			state[Nb*i+0] = tmp;
			s++;
		}
	}
}

void InvSubBytes(uint8_t* state){
  uint8_t i,j;
  for(i = 0; i < 4; i++){
	for(j = 0; j < 4; j++){
	  state[j + 4*i] = inv_s_box[state[j + 4*i]];
	}
  }
}

void InvMixColumns(uint8_t* state){
	uint8_t i;
	uint8_t a, b, c, d;
	for(i = 0; i < 4; i++){
		a = state[i];
		b = state[4+i];
        c = state[2*4+i];
        d = state[3*4+i];

		state[i] = gf_mult(0x0e, a) ^ gf_mult(0x0b, b) ^ gf_mult(0x0d, c) ^ gf_mult(0x09, d);
		state[4+i] = gf_mult(0x09, a) ^ gf_mult(0x0e, b) ^ gf_mult(0x0b, c) ^ gf_mult(0x0d, d);
		state[2*4+i] = gf_mult(0x0d, a) ^ gf_mult(0x09, b) ^ gf_mult(0x0e, c) ^ gf_mult(0x0b, d);
		state[3*4+i] = gf_mult(0x0b, a) ^ gf_mult(0x0d, b) ^ gf_mult(0x09, c) ^ gf_mult(0x0e, d);
	}
}

void TestInvShftRows(){
	uint8_t state[4*4] = {0xd4, 0xe0, 0xb8, 0x1e,
						  0xbf, 0xb4, 0x41, 0x27,
						  0x5d, 0x52, 0x11, 0x98,
						  0x30, 0xae, 0xf1, 0xe5};

	InvShftRows(state);
    for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%02X ", state[j + 4*i]);
		}
		printf("\n");
	}
    printf("--------------------\n");
    assert(state[0] == 0xd4);
    assert(state[1] == 0xe0);
    assert(state[2] == 0xb8);
    assert(state[3] == 0x1e);
    assert(state[4] == 0x27);
    assert(state[5] == 0xbf);
    assert(state[6] == 0xb4);
    assert(state[7] == 0x41);
    assert(state[8] == 0x11);
    assert(state[9] == 0x98);
    assert(state[10] == 0x5d);
    assert(state[11] == 0x52);
    assert(state[12] == 0xae);
    assert(state[13] == 0xf1);
    assert(state[14] == 0xe5);
    assert(state[15] == 0x30);
}

void TestInvSubBytes(){
	uint8_t state[4*4] = {0xd4, 0xe0, 0xb8, 0x1e,
						  0x27, 0xbf, 0xb4, 0x41,
						  0x11, 0x98, 0x5d, 0x52,
						  0xae, 0xf1, 0xe5, 0x30};

	InvSubBytes(state);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%02X ", state[j + 4*i]);
		}
		printf("\n");
	}
	printf("--------------------\n");
	assert(state[0] == 0x19);
    assert(state[1] == 0xa0);
    assert(state[2] == 0x9a);
    assert(state[3] == 0xe9);
    assert(state[4] == 0x3d);
    assert(state[5] == 0xf4);
    assert(state[6] == 0xc6);
    assert(state[7] == 0xf8);
    assert(state[8] == 0xe3);
    assert(state[9] == 0xe2);
    assert(state[10] == 0x8d);
    assert(state[11] == 0x48);
    assert(state[12] == 0xbe);
    assert(state[13] == 0x2b);
    assert(state[14] == 0x2a);
    assert(state[15] == 0x08);
}

void TestInvMixColumns(){
	uint8_t state[4*4] = {0x04, 0xe0, 0x48, 0x28,
						  0x66, 0xcb, 0xf8, 0x06,
						  0x81, 0x19, 0xd3, 0x26,
						  0xe5, 0x9a, 0x7a, 0x4c};

	InvMixColumns(state);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%02X ", state[j + 4*i]);
		}
		printf("\n");
	}
	printf("--------------------\n");
	assert(state[0] == 0xd4);
	assert(state[1] == 0xe0);
	assert(state[2] == 0xb8);
	assert(state[3] == 0x1e);
	assert(state[4] == 0xbf);
	assert(state[5] == 0xb4);
	assert(state[6] == 0x41);
	assert(state[7] == 0x27);
	assert(state[8] == 0x5d);
	assert(state[9] == 0x52);
	assert(state[10] == 0x11);
	assert(state[11] == 0x98);
	assert(state[12] == 0x30);
	assert(state[13] == 0xae);
	assert(state[14] == 0xf1);
	assert(state[15] == 0xe5);
}
