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


