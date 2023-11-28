/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:43:15 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 14:39:41 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
    private:
        std::string const name;
        bool indicator;
        const int grade_tosign;
        const int grade_toexec;
    public:
        class GradeTooHighException : public std::exception{
            public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char* what() const throw();
        };
        Form();
        Form(std::string const name, int grade_tosign, int grade_toexec);
        ~Form();
        Form(Form &object);
        Form operator=(Form&  object);

        std::string getName();
        int getGradeSign();
        bool isFormSigned() const;
        int getExecuteGrade() const;
        void beSigned(Bureaucrat& object);
};
std::ostream& operator<<(std::ostream& stream,  Form& form);
