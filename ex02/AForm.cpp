/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:44:49 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:35:59 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int AForm::getGradeSign() const{
    return this->grade_tosign;
}
int AForm::getExecuteGrade() const
{
    return this->grade_toexec;
}

bool AForm::isFormSigned() const
{
    return this->indicator;    
}

AForm::AForm() : name("Amine") , grade_tosign(10) , grade_toexec(10)
{
    std::cout << "default constructor called" << std::endl;
    this->indicator = false;
}
AForm::AForm(AForm &object) : name(object.name) , grade_tosign(object.grade_tosign) , grade_toexec(object.grade_toexec)
{
    std::cout << "copy constructor called" << std::endl;
    this->indicator = object.indicator;
    *this = object;
}
AForm& AForm::operator=(AForm& object)
{
     std::cout << "copy assignement called" << std::endl;
     this->indicator = object.indicator;
     return *this;
}

AForm::~AForm()
{
    std::cout << "Destrucor called" << std::endl;
}
AForm::AForm(const std::string  name, const int grade_tosign, const  int grade_toexec) : name(name) , grade_tosign(grade_tosign), grade_toexec(grade_toexec)
{
    if (grade_tosign < 1 || grade_toexec < 1)
    {
        throw AForm::GradeTooHighException();
    }
    else if (grade_tosign > 150 || grade_toexec > 150)
    {
        throw AForm::GradeTooLowException();
    }
    this->indicator = false;
}
std::string AForm::getName()
{
    return(this->name);
}

void AForm::beSigned(Bureaucrat& object_br)
{
    if (object_br.getGrade() > this->grade_tosign)
        throw AForm::GradeTooLowException();
    this->indicator = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("GradeTooHigh");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}
std::ostream& operator<<(std::ostream& stream,  AForm& form){
    stream << "Name : " <<  form.getName() << std::endl   << "is_signed : " << form.isFormSigned() << std::endl << "Sign Grade : " << form.getGradeSign() << std::endl << "execute grade : " << form.getExecuteGrade() << std::endl;
    return stream;
}
void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else if (this->isFormSigned() == false)
    {
        throw AForm::GradeTooHighException();
    }
}