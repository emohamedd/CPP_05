/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:44:49 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 15:03:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int Form::getGradeSign(){
    return this->grade_tosign;
}
int Form::getExecuteGrade() const
{
    return this->grade_toexec;
}

bool Form::isFormSigned() const
{
    return this->indicator;    
}

Form::Form() : name("Amine") , grade_tosign(10) , grade_toexec(10)
{
    std::cout << "default constructor called" << std::endl;
    this->indicator = false;
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
     this->indicator = object.indicator;
     return *this;
}

Form::~Form()
{
    std::cout << "Destrucor called" << std::endl;
}
Form::Form(const std::string  name, const int grade_tosign, const  int grade_toexec) : name(name) , grade_tosign(grade_tosign), grade_toexec(grade_toexec)
{
    if (grade_tosign < 1 || grade_toexec < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (grade_tosign > 150 || grade_toexec > 150)
    {
        throw Form::GradeTooLowException();
    }
    this->indicator = false;
}
std::string Form::getName()
{
    return(this->name);
}

void Form::beSigned(Bureaucrat& object_br)
{
    if (object_br.getGrade() > this->grade_tosign)
        throw Form::GradeTooLowException();
    this->indicator = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("GradeTooHigh");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLow");
}
std::ostream& operator<<(std::ostream& stream,  Form& form){
    stream << "Name : " <<  form.getName() << std::endl   << "is_signed : " << form.isFormSigned() << std::endl << "Sign Grade : " << form.getGradeSign() << std::endl << "execute grade : " << form.getExecuteGrade() << std::endl;
    return stream;
}