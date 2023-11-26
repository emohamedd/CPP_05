/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:21:47 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/24 16:31:39 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat("Amine" , -100);
        Bureaucrat("Amine" , 200);
    }
    catch (Bureaucrat::GradeTooLowException &object)
    {
        std::cerr << object.what()  << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &object)
    {
        std::cerr << object.what()  << std::endl;
    }
}