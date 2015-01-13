/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringTypeChecker.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:54:43 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/13 13:54:44 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "StringTypeChecker.hpp"
#include <limits>

StringTypeChecker::StringTypeChecker(){
	this->_str = "";
	this->_isChar = false;	
	this->_isInt = false;	
	this->_isFloat = false;	
	this->_isDouble = false;	
	return;
}

StringTypeChecker::StringTypeChecker( std::string strToCheck ) :_str(strToCheck){
	this->_isChar = false;	
	this->_isInt = false;	
	this->_isFloat = false;	
	this->_isDouble = false;	
	this->_setTypeFromInput(strToCheck);
}

StringTypeChecker::~StringTypeChecker(){
	return;
}

StringTypeChecker::StringTypeChecker(StringTypeChecker const & src){
	*this = src;
}


StringTypeChecker const &		StringTypeChecker::operator=(StringTypeChecker const & src){
	/*create copy function here*/
	(void)src;
	return *this;
}

void							StringTypeChecker::_setTypeFromInput(std::string input){	
	int type;
	if ( (type = checkInput(input)) == 0) {
		this->_isChar = true;	
		this->_isInt = true;	
		this->_isFloat = true;	
		this->_isDouble = true;	
		this->_valInt = static_cast<int>(this->_valChar);
		this->_valFloat = static_cast<float>(this->_valChar);
		this->_valDouble = static_cast<double>(this->_valChar);
	} else if ( type == 1 ){
		if (this->_valInt <= std::numeric_limits<char>::max() && this->_valInt >= std::numeric_limits<char>::min()){
			this->_isChar = true;
			this->_valChar = static_cast<char>(this->_valInt);
		}
		this->_isInt = true;	
		this->_isFloat = true;	
		this->_isDouble = true;	
		this->_valFloat = static_cast<float>(this->_valInt);
		this->_valDouble = static_cast<double>(this->_valInt);
	} else if ( type == 2 ){
		if (this->_valFloat <= std::numeric_limits<int>::max() && this->_valFloat >= std::numeric_limits<int>::min()){
			this->_isInt = true;	
			this->_valInt = static_cast<int>(this->_valFloat);
			if (this->_valInt <= std::numeric_limits<char>::max() && this->_valInt >= std::numeric_limits<char>::min()){
				this->_isChar = true;
				this->_valChar = static_cast<char>(this->_valInt);
			}
		}
		this->_isFloat = true;
		this->_isDouble = true;
		this->_valDouble = static_cast<double>(this->_valFloat);
	} else if (type == 3){
		if (this->_valDouble <= std::numeric_limits<float>::max() && this->_valDouble >= std::numeric_limits<float>::min()){
			this->_isFloat = true;	
			this->_valChar = static_cast<float>(this->_valFloat);
			if (this->_valFloat <= std::numeric_limits<int>::max() && this->_valFloat >= std::numeric_limits<int>::min()){
				this->_isInt = true;	
				this->_valInt = static_cast<int>(this->_valFloat);
				if (this->_valInt <= std::numeric_limits<char>::max() && this->_valInt >= std::numeric_limits<char>::min()){
					this->_isChar = true;
					this->_valChar = static_cast<char>(this->_valInt);
				}
			}
		}
		this->_valDouble = true;
	}
}



	std::ostream &		operator<<(std::ostream & o, StringTypeChecker const & i){
		if (i.getStr() == "0"){
		} 
		std::cout << "char: " << i.getValCharStr() << std::endl;
		std::cout << "int: " << i.getValIntStr() << std::endl;
		std::cout << "float: " << i.getValFloatStr() << std::endl;
		std::cout << "double: " << i.getValDoubleStr() << std::endl;
		return o;
	}

	bool			StringTypeChecker::getIsChar( void ) const {
		return this->_isChar;
	}

	bool			StringTypeChecker::getIsInt( void ) const {
		return this->_isInt;
	}

	bool			StringTypeChecker::getIsFloat( void ) const{
		return this->_isFloat;
	}

	bool			StringTypeChecker::getIsDouble( void )const {
		return this->_isDouble;
	}

	std::string		StringTypeChecker::getStr( void ) const {
		return this->_str;
	}

	std::string			StringTypeChecker::getValCharStr( void ) const{
		std::stringstream ss;
		ss << this->_valChar;
		return ss.str();
	}

	std::string				StringTypeChecker::getValIntStr( void ) const{
		std::stringstream ss;
		ss << this->_valInt;
		return ss.str();
	}

	std::string			StringTypeChecker::getValFloatStr( void ) const{
		std::stringstream ss;
		ss << this->_valFloat << 'f';
		return ss.str();
	}

	std::string			StringTypeChecker::getValDoubleStr( void ) const{
		std::stringstream ss;
		ss << this->_valDouble;
		return ss.str();
	}
int					StringTypeChecker::checkInput(std::string str){
	int i = 0;
	int ret = 0;
	std::string::iterator it;
	bool isDigit = false;
	for(it = str.begin(); it < str.end(); it++, i++){
		
	}
}


