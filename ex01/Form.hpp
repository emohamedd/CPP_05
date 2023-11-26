/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:43:15 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/26 20:37:11 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Form{
    private:
        std::string const name;
        bool indicator;
        const int grade_tosign;
        const int grade_toexec;
    public:
        Form();
        Form(std::string const name, int grade_tosign, int grade_toexec);
        ~Form();
        Form(Form &object);
        Form operator=(Form&  object);
        class GradeTooHighException : public std::exception{
            public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char* what() const throw();
        };
         std::string getName();
        int getGradeSign();
};