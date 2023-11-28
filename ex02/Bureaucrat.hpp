/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:07:29 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
class AForm;
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
    // void  executeForm(AForm const & form)
    void signForm(AForm& form) const;
    void increment();
    void decrement();
    std::string getName();
    int getGrade() const;
};
std::ostream& operator<<(std::ostream& os,  Bureaucrat& point);