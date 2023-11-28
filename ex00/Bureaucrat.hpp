/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:59:33 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat{
    private:
        std::string const name;
        int grade;
    public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat &object);
    Bureaucrat operator=(Bureaucrat&  object);;
    class GradeTooHighException : public std::exception{
        public:
           virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
           virtual const char* what() const throw();
    };
    void increment();
    void decrement();
    std::string getName();
    int getGrade();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& point);