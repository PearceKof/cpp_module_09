/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:25:18 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/26 18:55:59 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
static bool isValidArg( char **arg )
{
	for ( size_t i(1) ; arg[i] ; i++ )
	{
		long overflowChecker(strtol(arg[i], NULL, 10));

		if ( overflowChecker < 0 || INT_MAX < overflowChecker )
			return false ;

		for ( size_t j(0) ; arg[i][j] != '\0' ; j++ )
		{
			if ( !isdigit(arg[i][j]) )
				return false ;
		}
	}
	
	return true ;
}

static void printValue( std::vector<int>& c )
{
	for ( std::vector<int>::iterator it(c.begin()) ; it != c.end() ; it++ )
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if ( ac < 2 || isValidArg(av) == false )
	{
		std::cout << "Error: bad arguments" << std::endl;
		return EXIT_FAILURE ;
	}
	
	std::vector<int> c_vector;
	std::deque<int> c_deque;
	std::set<int> c_duplicateChecker;

	for (size_t i(1) ; av[i] ; i++ )
	{
		int nb = atoi(av[i]);
		if ( c_duplicateChecker.find(nb) != c_duplicateChecker.end() )
		{
			std::cout << "Error: the number must not be duplicate" << std::endl;
			return EXIT_FAILURE ;
		}
		c_duplicateChecker.insert(nb);
		c_vector.push_back(nb);
		c_deque.push_back(nb);
	}
	
	std::cout << "Before: ";
	printValue(c_vector);
	
	std::time_t t_vector, t_deque;

	
	
	std::cout << "after: ";
	printValue(c_vector);

	return EXIT_SUCCESS ;
}