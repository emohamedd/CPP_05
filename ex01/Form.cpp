/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:44:49 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/26 20:41:22 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int Form::getGradeSign(){
    return this->grade_tosign;
}

Form::Form() : name("Amine") , grade_tosign(1) , grade_toexec(1)
{
    this->indicator = 0;
    std::cout << "default constructor called" << std::endl;
}
Form::Form(Form &object) : name(object.name) , grade_tosign(object.grade_tosign) , grade_toexec(object.grade_toexec)
{
    std::cout << "copy constructor called" << std::endl;
    this->indicator = object.indicator;
    *this = object;
}
Form Form::operator=(Form& object)
{
     std::cout << "copy assignement called" << std::endl;
     return *this;
}

Form::~Form()
{
    std::cout << "Destrucor called" << std::endl;
}
Form::Form(std::string const name, int grade_tosign, int grade_toexec) : name(name) , grade_tosign(grade_tosign), grade_toexec(grade_toexec)
{
    if (grade_tosign < 1 || grade_toexec < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (grade_tosign > 150 || grade_toexec > 150)
    {
        throw Form::GradeTooLowException();
    }
    this->indicator = indicator;
}
std::string Form::getName()
{
    return(this->name);
}


const char* Form::GradeTooHighException::what() const throw()
{
    return ("GradeTooHigh");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}