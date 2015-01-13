#include <iostream>
#include <limits>
#include "Data.hpp"

Data::Data( void ){
}

Data::Data(Data const & src) {
}

Data::~Data(){
}

Data::Data(std::string s1, int n, std::string s2){
	this->s1 = s1;
	this->n = n;
	this->s2 = s2;
}

Data  &	Data::operator=(Data const & d){
	return *this;	
}
