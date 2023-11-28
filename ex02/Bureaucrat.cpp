/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:40 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:19:43 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::getGrade() const{
    return this->grade;
}

Bureaucrat::Bureaucrat() : name("Amine")
{
    std::cout << "default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &object)
{
    std::cout << "copy constructor called" << std::endl;
    *this = object;
}
Bureaucrat Bureaucrat::operator=(Bureaucrat& object)
{
     std::cout << "copy assignement called" << std::endl;
     this->grade = object.grade;
     return *this;
     
}
std::ostream& operator<<(std::ostream& stream,  Bureaucrat& obj)
{
    stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return stream;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destrucor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}
std::string Bureaucrat::getName()
{
    return(this->name);
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GradeTooHigh");
}
void Bureaucrat::increment()
{
        this->grade--;
        if (this->grade < 1)
        {
             throw Bureaucrat::GradeTooHighException();
        }

}
void Bureaucrat::decrement()
{
    this->grade++;
     if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}

void Bureaucrat::signForm(AForm& form) const
{
    if (form.isFormSigned())
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->name << " could not sign " << form.getName() << "  the grade is low" << std::endl;    
}