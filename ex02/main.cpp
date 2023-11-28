/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:47 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:53 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm form("Tree");
		Bureaucrat amine("Amine", 138);
		std::cout << amine;
		std::cout << form;
		form.beSigned(amine);
		amine.signForm(form);
		form.execute(amine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}