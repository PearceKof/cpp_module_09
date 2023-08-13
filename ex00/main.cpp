/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:44:05 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/13 15:57:46 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <cerrno>
#include <fstream>

int main ( int ac, char **av )
{
	if ( ac <= 1 || 3 < ac)
	{
		std::cerr << "ERROR: bad arguments" << std::endl;
		return 1;
	}
	std::ifstream inputFile;
	std::ifstream dataBase;
	std::map<std::string, double>	map_csv;

	inputFile.open(av[1], std::ifstream::in);
	if ( inputFile.is_open() == false )
	{
		std::cerr << "ERROR: can't open " << av[1] << std::endl;
		return 1;
	}
	
	const char *dataBasePath = "./data.csv";
	if (ac == 3)
		dataBasePath = av[2];

	dataBase.open(dataBasePath, std::ifstream::in);
	if ( dataBase.is_open() == false )
	{
		std::cerr << "ERROR: can't open " << dataBasePath << std::endl;
		return 1;
	}
	return 0;
}