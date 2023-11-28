/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:28 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:13:02 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45)
{
    std::cout << "default constructor Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 72, 45)
{
    std::cout << "Parametric constructor Called" << std::endl;
    this->target = target;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destrucor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &object)
{
    std::cout << "copy constructor called" << std::endl;
    *this = object;
}
PresidentialPardonForm PresidentialPardonForm::operator=(PresidentialPardonForm& object)
{
     std::cout << "copy assignement called" << std::endl;
     this->target = object.target;
     return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else if (this->isFormSigned() == false)
    {
        throw AForm::GradeTooHighException();
    }
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}