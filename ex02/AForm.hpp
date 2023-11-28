/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:43:15 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:17:45 by emohamed         ###   ########.fr       */
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
        AForm operator=(AForm&  object);

        std::string getName();
        int getGradeSign() const;
        bool isFormSigned() const;
        int getExecuteGrade() const;
        void beSigned(Bureaucrat& object);
};
std::ostream& operator<<(std::ostream& stream,  AForm& Aform);
