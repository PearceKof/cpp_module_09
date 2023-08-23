/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:45:14 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/21 15:35:09 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : value(0), exRate(0) {}

BitcoinExchange::~BitcoinExchange() {}

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