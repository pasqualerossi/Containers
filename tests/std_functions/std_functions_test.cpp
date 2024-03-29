/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_functions_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:25:57 by esafar            #+#    #+#             */
/*   Updated: 2023/02/13 14:54:53 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../containers.hpp"

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);

    std::cout << "===============STD::EQUAL===============" << std::endl;

    if (std::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "std::equal: true" << std::endl;
    else
        std::cout << "std::equal: false" << std::endl;

    if (ft::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "ft::equal: true" << std::endl;
    else
        std::cout << "ft::equal: false" << std::endl;

    std::cout << std::endl;

    std::cout << "===============STD::LEXICO===============" << std::endl;

    if (std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "std::lexicographical_compare: true" << std::endl;
    else
        std::cout << "std::lexicographical_compare: false" << std::endl;
        
    if (ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "ft::lexicographical_compare: true" << std::endl;
    else
        std::cout << "ft::lexicographical_compare: false" << std::endl;

    std::boolalpha(std::cout << std::endl);
    
    std::cout << "===============STD::IS_INTEGRAL===============" << std::endl;
    
    std::cout << "is_integral<int> : " << std::is_integral<int>::value << std::endl;
    std::cout << "is_integral<int> : " << ft::is_integral<int>::value << std::endl << std::endl;
    
    std::cout << "is_integral<char> : " << std::is_integral<char>::value << std::endl;
    std::cout << "is_integral<char> : " << ft::is_integral<char>::value << std::endl << std::endl;
    
    std::cout << "is_integral<float> : " << std::is_integral<float>::value << std::endl;
    std::cout << "is_integral<float> : " << ft::is_integral<float>::value << std::endl << std::endl;
    
    std::cout << "is_integral<double> : " << std::is_integral<double>::value << std::endl;
    std::cout << "is_integral<double> : " << ft::is_integral<double>::value << std::endl << std::endl;
    
    std::cout << "is_integral<std::string> : " << std::is_integral<std::string>::value << std::endl;
    std::cout << "is_integral<std::string> : " << ft::is_integral<std::string>::value << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << "===============STD::PAIR===============" << std::endl;

    std::pair <std::string,double> std_product1;                     // default constructor
    std::pair <std::string,double> std_product2 ("tomatoes",2.30);   // value init
    std::pair <std::string,double> std_product3 (std_product2);          // copy constructor
    ft::pair <std::string,double> product1;                     // default constructor
    ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    ft::pair <std::string,double> product3 (product2);          // copy constructor
    
    std_product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
    product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    std_product2.first = "shoes";                  // the type of first is string
    std_product2.second = 39.90;                   // the type of second is double
    product2.first = "shoes";                  // the type of first is string
    product2.second = 39.90;                   // the type of second is double
    
    std::cout << "std:: The price of " << std_product1.first << " is $" << std_product1.second << '\n';
    std::cout << "ft:: The price of " << product1.first << " is $" << product1.second << "\n\n";

    std::cout << "std:: The price of " << std_product2.first << " is $" << std_product2.second << '\n';
    std::cout << "ft:: The price of " << product2.first << " is $" << product2.second << "\n\n";

    std::cout << "std:: The price of " << std_product3.first << " is $" << std_product3.second << '\n';
    std::cout << "ft:: The price of " << product3.first << " is $" << product3.second << "\n\n";

    std::cout << std::endl << std::endl;
    std::cout << "===============STD::ENABLE_IF===============" << std::endl;
    
    short int i = 1;    // code does not compile if type of i is not integral

    std::cout << std::boolalpha;
    
    std::cout << "std:: i is odd: " << is_odd_std(i) << std::endl;
    std::cout << "ft:: i is odd: " << is_odd_ft(i) << std::endl << std::endl;
    
    std::cout << "std:: i is even: " << is_even_std(i) << std::endl;
    std::cout << "ft:: i is even: " << is_even_ft(i) << std::endl;
    
    return (0);
}