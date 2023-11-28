/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:06:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 19:49:05 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
Intern::Intern()
{
    std::cout << "default constructor called" << std::endl;
}
Intern &Intern::operator=(Intern& object)
{
     std::cout << "copy assignement called" << std::endl;
     (void)object;
     return *this;
     
}
Intern::Intern(Intern  &object)
{
    std::cout << "copy constructor called" << std::endl;
    *this = object;
    
}
Intern::~Intern()
{
    std::cout << "Destrucor called" << std::endl;
}

int index(std::string form)
{
    if (form == "robotomy request")
        return 0;
    else if (form == "presidential pardon")
        return 1;
    else if (form == "shrubbery creation")
        return 2;
    else
        return -1;
}
AForm *Intern::makeForm(std::string form, std::string target)
{
    std::cout << "Intern creates " << form << std::endl;
    
    AForm *newForm = NULL;
    int i = index(form);
    switch (i)
    {
        case 0:
            newForm = new RobotomyRequestForm(target);
            break;
        case 1:
            newForm = new PresidentialPardonForm(target);
            break;
        case 2:
            newForm = new ShrubberyCreationForm(target);
            break;
        default:
            std::cout << "Form not found" << std::endl;
            break;
    }
    return newForm;
}
