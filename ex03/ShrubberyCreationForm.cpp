/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:30:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:17 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "default constructor Called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "Parametric constructor Called" << std::endl;
    this->target = target + "_shrubbery";
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destrucor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &object)
{
    std::cout << "copy constructor called" << std::endl;
    *this = object;
}
ShrubberyCreationForm ShrubberyCreationForm::operator=(ShrubberyCreationForm& object)
{
     std::cout << "copy assignement called" << std::endl;
     this->target = object.target;
     return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else if (this->isFormSigned() == false)
    {
        throw AForm::GradeTooHighException();
    }
    std::ofstream file(this->target.c_str());
    file << "                                     ." << std::endl;
    file << "                                   .         ;  " << std::endl;
    file << "                   .              .              ;%     ;;   " << std::endl;
    file << "                     ,           ,                :;%  %;   " << std::endl;
    file << "                      :         ;                   :;%;'     .,   " << std::endl;
    file << "             ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "               ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "                %;       %;%;      ,  ;       %;  ;%;   ,%;" << std::endl;
    file << "                 ;%;      %;        ;%;        % ;%;  ,%;" << std::endl;
    file << "                  `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "                   `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                      `:%;.  :;bd%;          %;@%;" << std::endl;
    file << "                        `@%:.  :;%.         ;@@%;" << std::endl;
    file << "                          `@%.  `;@%.      ;@@%;" << std::endl;
    file << "                            ;@%. :@%%  %@@%;" << std::endl;
    file << "                              %@bd%%%bd%%:;" << std::endl;
    file << "                                #@%%%%%:;;" << std::endl;
    file << "                                %@@%%%::;" << std::endl;
    file << "                                %@@@%(o);  . '         " << std::endl;
    file << "                                %@@@o%;:(.,'         " << std::endl;
    file << "                            `.. %@@@o%::;         " << std::endl;
    file << "                               `)@@@o%::;         " << std::endl;
    file << "                                %@@(o)::;        " << std::endl;
    file << "                               .%@@@@%::;         " << std::endl;
    file << "                              ;%@@@@%::;.          " << std::endl;
    file << "                             ;%@@@@%%:;;;. " << std::endl;
    file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
    file << "                                  EMMD" << std::endl;

    file.close();
}