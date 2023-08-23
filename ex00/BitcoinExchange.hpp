/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:44:20 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/21 15:34:13 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINECHANGE_HPP
# define BITCOINECHANGE_HPP

# include <iostream>

class BitcoinExchange
{
	private:
		std::string date;
		double value;
		double exRate;
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void setDate(std::string _date);
		void setValue(double _value);
		void setExchangeRate(double _exRate);

		void printMultipledResult() const;
};

#endif