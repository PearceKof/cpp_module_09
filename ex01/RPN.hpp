/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:01:08 by blaurent          #+#    #+#             */
/*   Updated: 2023/08/30 16:36:07 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

class RPN
{
private:
	std::stack< int > container;
	int result;
public:
	RPN();
	RPN(const RPN& src);
	~RPN();
	RPN& operator=(const RPN& rhs);
	
	bool calculate(std::string av);
	int getResult() const;
};

#endif