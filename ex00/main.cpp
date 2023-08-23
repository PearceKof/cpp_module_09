/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:44:05 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/21 15:45:37 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <cerrno>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <sstream>

static bool isValidDate(std::string date)
{
	std::istringstream iss(date);
	int year;
	int month;
	int day;
	char del1;
	char del2;

	std::tm timeInfoChecker = {};
	
	iss >> year >> del1 >> month >> del2 >> day;
	
	
	timeInfoChecker.tm_mday = day;
	timeInfoChecker.tm_mon = month - 1;
	timeInfoChecker.tm_year = year - 1900;
	
	std::mktime(&timeInfoChecker);
	if ( del1 != '-' || del2 != '-'
		|| timeInfoChecker.tm_mday != day
		|| timeInfoChecker.tm_mon != month - 1
		|| timeInfoChecker.tm_year != year - 1900 )
		return false ;
	return true ;
}

static bool isValidExchangeRate(double exRate)
{
	return 0 <= exRate ;
}

static bool getDataFromCsv(std::ifstream& input, std::map<std::string, double>& map_csv)
{
	std::string buffer;

	std::getline(input, buffer);
	if ( buffer != "date,exchange_rate" )
	{
		std::cerr << "ERROR: invalid format: first line must begin with \"date,exchange_rate\"" << std::endl;
		return true ;
	}
	

	while ( std::getline(input, buffer) )
	{
		std::string gl_date;
		std::string gl_exchangeRate;
		std::istringstream iss(buffer);

		getline(iss, gl_date, ',');
		// std::cout << "readed line: " << gl_date << std::endl;
		if ( isValidDate(gl_date) == false )
		{
			std::cerr << "ERROR: " << gl_date << " is an invalid date format" << std::endl;
			return true ;
		}
		
		getline(iss, gl_exchangeRate, '\0');
		double exRate = std::strtod(gl_exchangeRate.c_str(), NULL);
		if ( isValidExchangeRate(exRate) == false )
		{
			std::cerr << "ERROR: " << gl_exchangeRate << " is an invalid exchange rate format" << std::endl;
			return true ;
		}
		
		map_csv.insert(std::pair<std::string, double>(gl_date, exRate));
	}
	
	return false ;
}

static bool getDataFromInput(std::ifstream& input, std::map<std::string, double>& map_csv)
{
	std::string buffer;

	std::getline(input, buffer);
	if ( buffer != "date | value" )
	{
		std::cerr << "ERROR: invalid format: first line must begin with \"date | value\"" << std::endl;
		return true ;
	}

	
	BitcoinExchange	btc;
	while ( std::getline(input, buffer) )
	{
		std::string gl_date;
		std::string gl_value;
		std::string del;
		std::istringstream iss(buffer);

		iss >> gl_date >> del >> gl_value;

		if ( isValidDate(gl_date) == false )
		{
			std::cerr << "ERROR: bad input => " << gl_date << std::endl;
			continue ;
		}
		
		double value = std::strtod(gl_value.c_str(), NULL);
		if ( value < 0 )
		{
			std::cerr << "ERROR: not a positive number." << std::endl;
			continue ;
		}
		if ( 1000 < value )
		{
			std::cerr << "ERROR: too large a number." << std::endl;
			continue ;
		}
		if (del != "|")
		{
			std::cout << "It's not a correct delimeter." << std::endl;
			continue ;
		}

		std::map< std::string, double >::iterator it_lowerDate = map_csv.lower_bound(gl_date);

		if ( (*it_lowerDate).first != gl_date )
		{
			if ( it_lowerDate != map_csv.begin() )
			{
				it_lowerDate--;
			}
		}
		btc.setValue(value);
		btc.setDate(gl_date);
		btc.setExchangeRate((*it_lowerDate).second);

		btc.printMultipledResult();
	}
	

	return false ;
}

int main ( int ac, char **av )
{
	if ( ac <= 1 || 3 < ac)
	{
		std::cerr << "ERROR: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream inputFile;

	inputFile.open(av[1], std::ifstream::in);
	if ( inputFile.is_open() == false )
	{
		std::cerr << "ERROR: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream dataBase;
	
	const char *dataBasePath = "./data.csv";
	if (ac == 3)
		dataBasePath = av[2];

	dataBase.open(dataBasePath, std::ifstream::in);
	if ( dataBase.is_open() == false )
	{
		std::cerr << "ERROR: could not open file." << std::endl;
		if ( inputFile.is_open() == true )
			inputFile.close();
		return EXIT_FAILURE ;
	}

	std::map< std::string, double >	map_csv;

	if ( getDataFromCsv(dataBase, map_csv) )
		return EXIT_FAILURE;

	if ( getDataFromInput(inputFile, map_csv) )
		return EXIT_FAILURE ;

	return EXIT_SUCCESS ;
}