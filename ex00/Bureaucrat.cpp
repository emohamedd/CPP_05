/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:40 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/24 16:48:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::getGrade(){
    return this->grade;
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

