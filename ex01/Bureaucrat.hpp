/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:55 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"
class Form;
class Bureaucrat{
    private:
        std::string const name;
        int grade;
    public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat &object);
    Bureaucrat operator=(Bureaucrat&  object);
    class GradeTooHighException : public std::exception{
        public:
           virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
           virtual const char* what() const throw();
    };
    void signForm(Form& form) const;
    void increment();
    void decrement();
    std::string getName();
    int getGrade();
};
std::ostream& operator<<(std::ostream& os,  Bureaucrat& point);