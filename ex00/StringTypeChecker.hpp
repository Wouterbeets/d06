/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringTypeChecker.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:54:38 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/13 13:54:41 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGtYPEcHECKER_HPP
# define STRINGtYPEcHECKER_HPP

#include <iostream>

class StringTypeChecker
{
	public:
		StringTypeChecker( void );
		StringTypeChecker(std::string strToCheck);
		virtual ~StringTypeChecker();
		StringTypeChecker(StringTypeChecker const & src);
		StringTypeChecker const &		operator=(StringTypeChecker const & i);

		bool			getIsChar( void ) const;
		bool			getIsInt( void )  const;
		bool			getIsFloat( void ) const;
		bool			getIsDouble( void ) const;
		std::string		getStr( void ) const;

		std::string			getValCharStr( void ) const;
		std::string				getValIntStr( void )const;
		std::string			getValFloatStr( void )const;
		std::string			getValDoubleStr( void )const;
		int					checkInput(std::string str);

	private:
		void		_setTypeFromInput(std::string input);
		bool			_isChar;
		bool			_isInt;
		bool			_isFloat;
		bool			_isDouble;
		std::string		_str;
		char			_valChar;
		int				_valInt;
		float			_valFloat;
		double			_valDouble;

		//bool			isOnlyDigit(std::string);
		//bool			fitsInInt(input);

};
std::ostream &		operator<<(std::ostream & o, StringTypeChecker const & i);
#endif /*STRINGtYPEcHECKER_HPP*/
