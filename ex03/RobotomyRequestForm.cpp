/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:29:06 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:58:39 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "default constructor Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "Parametric constructor Called" << std::endl;
    this->target = target;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destrucor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &object)
{
    std::cout << "copy constructor called" << std::endl;
    *this = object;
}
RobotomyRequestForm RobotomyRequestForm::operator=(RobotomyRequestForm& object)
{
     std::cout << "copy assignement called" << std::endl;
     this->target = object.target;
     return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else if (this->isFormSigned() == false)
    {
        throw AForm::GradeTooHighException();
    }
    srand(time(NULL));
    if (rand() % 2 == 0)
    {
        std::cout << "Brrrzzzzzzzzz" << std::endl;
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << this->target << " has not been robotomized successfully" << std::endl;
    }
    
}