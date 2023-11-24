/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:40 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/24 16:16:30 by emohamed         ###   ########.fr       */
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
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}

