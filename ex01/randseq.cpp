
#include <iostream>
#include <limits>
#include <time.h>
#include "Data.hpp"

char		getChar(){
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	return alphanum[rand() % 71];
}

void	*serialize(){
	srand(time(NULL));
	Data d("this", 2, "test");
	int n = rand() % std::numeric_limits<int>::max();
	char *ser = new char[16 + sizeof(int)];
	char s[8];
	for(int i = 0; i < 8; i++){
		s[i] = getChar();
	}
	*ser = (*ser << 8 * 8) | *s;
	*ser = (*ser << 32 ) | n;
	char s2[8];
	for(int i = 0; i < 8; i++){
		s2[i] = getChar();
	}
	*ser = (*ser << 8 * 8) | *s2;
	

}

int main(){
	void *ser = serialize();
	Data *data = deserialize(ser);

	std::cout << data->str1 << data->n << data->str2 << std::endl;
	return 0;
}
