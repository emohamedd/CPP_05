/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:43:15 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 18:35:34 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm{
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
        AForm();
        AForm(std::string const name, int grade_tosign, int grade_toexec);
        ~AForm();
        AForm(AForm &object);
        AForm& operator=(AForm& object);
        std::string getName();
        int getGradeSign() const;
        int getExecuteGrade() const;
        bool isFormSigned() const;
        void beSigned(Bureaucrat& object);
        virtual void execute(Bureaucrat const &executor) const = 0;
};
std::ostream& operator<<(std::ostream& stream,  AForm& Aform);
