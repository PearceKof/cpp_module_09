/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:45:14 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/30 15:53:00 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : value(0), exRate(0), date("") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : value(src.value), exRate(src.exRate), date(src.date) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		this->date = rhs.date;
		this->value = rhs.value;
		this->exRate = rhs.exRate;
	}
	
	return *this ;
}

void	BitcoinExchange::setDate(std::string _date)
{
	date = _date;
}

void	BitcoinExchange::setValue(double _value)
{
	value = _value;
}

void	BitcoinExchange::setExchangeRate(double _exRate)
{
	exRate = _exRate;
}

void	BitcoinExchange::printMultipledResult() const
{
	std::cout << date << " => " << value << " = " << value * exRate << std::endl;
}