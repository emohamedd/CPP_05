/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:47 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:00:02 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ShrubberyCreationForm
// int main()
// {
// 	try
// 	{
// 		ShrubberyCreationForm form("Tree");
// 		Bureaucrat amine("Amine", 138);
// 		std::cout << amine;
// 		std::cout << form;
// 		form.beSigned(amine);
// 		amine.signForm(form);
// 		form.execute(amine);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// }

// RobotMyrequestForm
// int main()
// {
// 	try
// 	{
// 		RobotomyRequestForm form("Robot");
// 		Bureaucrat amine("Amine", 10);
// 		std::cout << amine;
// 		std::cout << form;
// 		form.beSigned(amine);
// 		amine.signForm(form);
// 		form.execute(amine);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// }

//PresidentialPardonForm
int main()
{
	try
	{
		PresidentialPardonForm form("Hassan");
		Bureaucrat amine("Hassan", 10);
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