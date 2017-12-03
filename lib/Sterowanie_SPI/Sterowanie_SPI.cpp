#ifndef STEROWANIE_SPI_CPP
#define STEROWANIE_SPI_CPP

#include <Sterowanie_SPI.h>

int16_t hascii32dec(uint8_t* ptext){
	uint8_t* p;
	uint16_t t;

	p=ptext;
	t=0;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*256;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*256;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*16;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*16;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48);
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55);
	}

	return t;
};

int16_t hascii22dec(uint8_t* ptext){
	uint8_t* p;
	uint16_t t;

	p=ptext;
	t=0;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*16;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*16;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48);
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55);
	}

	return t;
};

void dec2hascii3(uint16_t liczba, uint8_t tab[3]){
	uint16_t tmp;

	if(liczba<4096){
		tmp=liczba/256;
		if(tmp>=0 && tmp<=9){
			tab[0]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[0]=tmp+55;
		}
		tmp=(liczba%256)/16;
		if(tmp>=0 && tmp<=9){
			tab[1]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[1]=tmp+55;
		}
		tmp=(liczba%16);
		if(tmp>=0 && tmp<=9){
			tab[2]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[2]=tmp+55;
		}
	}
};


int16_t hascii42dec(uint8_t* ptext){

	return 0;
};


void dec2hascii4(int16_t liczba, uint8_t tab[4]){

};


int32_t hascii82dec(uint8_t* ptext){
	uint8_t* p;
	int32_t t;

	p=ptext;
	t=0;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x10000000;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x10000000;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x1000000;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x1000000;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x100000;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x100000;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x10000;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x10000;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x1000;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x1000;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x100;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x100;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48)*0x10;
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55)*0x10;
	}
	++p;
	if(*p>='0' && *p<='9'){
		t+=(*p-48);
	}else if(*p>='A' && *p<='F'){
		t+=(*p-55);
	}

	return t;

};


void dec2hascii8(int32_t liczba, uint8_t tab[8]){
	uint32_t tmp, liczbau;

	liczbau = (uint32_t)liczba;


		tmp=liczbau/0x10000000;
		if(tmp>=0 && tmp<=9){
			tab[0]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[0]=tmp+55;
		}
		tmp=(liczbau%0x10000000)/0x1000000;
		if(tmp>=0 && tmp<=9){
			tab[1]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[1]=tmp+55;
		}
		tmp=(liczbau%0x1000000)/0x100000;
		if(tmp>=0 && tmp<=9){
			tab[2]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[2]=tmp+55;
		}
		tmp=(liczbau%0x100000)/0x10000;
		if(tmp>=0 && tmp<=9){
			tab[3]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[3]=tmp+55;
		}
		tmp=(liczbau%0x10000)/0x1000;
		if(tmp>=0 && tmp<=9){
			tab[4]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[4]=tmp+55;
		}
		tmp=(liczbau%0x1000)/0x100;
		if(tmp>=0 && tmp<=9){
			tab[5]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[5]=tmp+55;
		}
		tmp=(liczbau%0x100)/0x10;
		if(tmp>=0 && tmp<=9){
			tab[6]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[6]=tmp+55;
		}
		tmp=(liczbau%16);
		if(tmp>=0 && tmp<=9){
			tab[7]=tmp+48;
		}else if(tmp>=10 && tmp<=15){
			tab[7]=tmp+55;
		}
};

#endif
