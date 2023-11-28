/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:47 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 15:50:13 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Aflatone("Aflatone", 40);
		std::cout << Aflatone;
		Bureaucrat amine("Amine", 10);
		std::cout << amine;
		Form form("Mo3ahadat Versay", 20, 30);
		Form form2("Mo3ahadat LALA mghnia", 30, 30);
		std::cout << form;
		std::cout << form2;
		form.beSigned(amine);
		amine.signForm(form);
		form2.beSigned(Aflatone);
		Aflatone.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}