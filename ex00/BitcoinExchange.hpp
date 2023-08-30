/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:44:20 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/30 16:15:04 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINECHANGE_HPP
# define BITCOINECHANGE_HPP

# include <iostream>
# include <string>

class BitcoinExchange
{
	private:

		double		value;
		double		exRate;
		std::string	date;

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		void	setDate(std::string _date);
		void	setValue(double _value);
		void	setExchangeRate(double _exRate);

		void	printMultipledResult() const;
};

#endif