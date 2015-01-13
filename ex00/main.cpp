/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:14:14 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/13 11:14:16 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include "StringTypeChecker.hpp"

int	main(int argc, char **argv){
	if (argc == 2){
		std::string  str(argv[1]);
		StringTypeChecker s(str);
		std::cout << s << std::endl;
	} else {
		std::cout << "Usage: "<< argv[0] << " [<char value>|<float value>|<int value>|<double value>]"<< std::endl;
	}
}
