#ifndef STEROWANIE_SPI_H
#define STEROWANIE_SPI_H

#include <Pinout.h>
#include <Arduino.h>


#define PIPE 0xE8E8F0F0E1LL
#define RAMKA 15

char ramka[RAMKA];

int16_t hascii32dec(uint8_t* ptext);

int16_t hascii22dec(uint8_t* ptext);

void dec2hascii3(uint16_t liczba, uint8_t tab[3]);

int16_t hascii42dec(uint8_t* ptext);

void dec2hascii4(int16_t liczba, uint8_t tab[4]);

int32_t hascii82dec(uint8_t* ptext);

void dec2hascii8(int32_t liczba, uint8_t tab[8]);

#endif
