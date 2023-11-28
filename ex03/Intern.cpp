/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:06:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 19:34:34 by emohamed         ###   ########.fr       */
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
AForm *Intern::makeForm(std::string form, std::string target)
{
    std::cout << "Intern creates " << form << std::endl;
    
    AForm *newForm = NULL;
    
   switch (form[0])
   {
       case 'r':
            newForm = new RobotomyRequestForm(target);
            break;
        case 'p':
            newForm = new PresidentialPardonForm(target);
            break;
        case 's':
            newForm = new ShrubberyCreationForm(target);
            break;
        default:
            std::cout << "Form not found" << std::endl;
            break;
   }
    return newForm;
}
