/*
 * aes_key.h
 *
 *  Created on: Mar 17, 2025
 *      Author: reppl
 */

#ifndef AES_KEY_AES_KEY_H_
#define AES_KEY_AES_KEY_H_

#include "SBox.h"
#include "coef_function.h"

void aes_key_expansion(uint8_t* key, uint8_t* word);

#endif /* AES_KEY_AES_KEY_H_ */
