/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:54:44 by esafar            #+#    #+#             */
/*   Updated: 2023/02/13 14:56:52 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../containers.hpp"

template <typename T1, typename T2>
static void test_default_constructor()
{
    ft::map<T1, T2> a;

    assert(a.empty());

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    for (int i = 0; i < 50; i++)
        assert(a.insert(ft::make_pair<T1, T2>(T1(), T2())).second == false);

    assert(a.size() == 1);
    typename ft::map<T1, T2>::iterator it = a.begin();
    assert(a.insert(ft::make_pair<T1, T2>(T1(), T2())).first == it);
}

static void default_constructor()
{
    test_default_constructor<char, int>();
    test_default_constructor<int, int>();
    test_default_constructor<float, char>();
    test_default_constructor<char *, int>();
    test_default_constructor<int, std::string>();

    std::cout <<  "default constructor: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_range_constructor()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.size() == 1);

    ft::map<T1, T2> b(a.begin(), a.end());

    assert(b.size() == 1);

    b.erase(b.begin());
    assert(b.empty());
    assert(a.size() == 1);
}

static void range_constructor()
{
    test_range_constructor<char, int>();
    test_range_constructor<int, int>();
    test_range_constructor<float, char>();
    test_range_constructor<char *, int>();
    test_range_constructor<int, std::string>();

    std::cout <<  "range constructor: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_copy_constructor()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.size() == 1);

    ft::map<T1, T2> b(a);

    assert(b.size() == 1);

    b.erase(b.begin());
    assert(b.empty());
    assert(a.size() == 1);
}

static void copy_constructor()
{
    test_copy_constructor<char, int>();
    test_copy_constructor<int, int>();
    test_copy_constructor<float, char>();
    test_copy_constructor<char *, int>();
    test_copy_constructor<int, std::string>();

    std::cout <<  "copy constructor: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_assignement_operator()
{
    ft::map<T1, T2> a;
    ft::map<T1, T2> b;

    a = b;

    assert(a.empty());
    assert(b.empty());

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    b = a;

    assert(a.size() == 1);
    assert(b.size() == 1);

    a.erase(a.begin());

    assert(a.empty());
    assert(b.size() == 1);
}

static void assignement_operator()
{
    test_assignement_operator<char, int>();
    test_assignement_operator<int, int>();
    test_assignement_operator<float, char>();
    test_assignement_operator<char *, int>();
    test_assignement_operator<int, std::string>();

    std::cout <<  "assignement operator: " <<  "OK" << std::endl;
}

static void test_begin_end_practical()
{
    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));

    assert((*(a.begin())).first == 'a');
    assert((*(++a.begin())).first == 'b');

    assert((*(--a.end())).first == 'b');
}

template <typename T1, typename T2>
static void test_begin_end()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    size_t count = 0;
    for (typename ft::map<T1, T2>::iterator it = a.begin(); it != a.end(); it++)
    {
        assert((*(it)).first == T1());
        assert((*(it)).second == T2());
        count++;
    }
    assert(count == a.size() && count == 1);
}

static void begin_end()
{
    test_begin_end_practical();
    test_begin_end<char, int>();
    test_begin_end<int, int>();
    test_begin_end<float, char>();
    test_begin_end<char *, int>();
    test_begin_end<int, std::string>();

    std::cout <<  "begin end: " <<  "OK" << std::endl;
}

static void test_rbegin_rend_practical()
{
    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));

    assert((*(a.rbegin())).first == 'b');
    assert((*(++a.rbegin())).first == 'a');

    assert((*(--a.rend())).first == 'a');
}

template <typename T1, typename T2>
static void test_rbegin_rend()
{

    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    size_t count = 0;
    for (typename ft::map<T1, T2>::reverse_iterator it = a.rbegin(); it != a.rend(); it++)
    {
        assert((*(it)).first == T1());
        assert((*(it)).second == T2());
        count++;
    }
    assert(count == a.size() && count == 1);
}

static void rbegin_rend()
{
    test_rbegin_rend_practical();
    test_rbegin_rend<char, int>();
    test_rbegin_rend<int, int>();
    test_rbegin_rend<float, char>();
    test_rbegin_rend<char *, int>();
    test_rbegin_rend<int, std::string>();

    std::cout <<  "rbegin rend: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_empty()
{
    ft::map<T1, T2> a;

    assert(a.empty());

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(!a.empty());

    a.erase(a.begin());
    assert(a.empty());
}

static void empty()
{
    test_empty<char, int>();
    test_empty<int, int>();
    test_empty<float, char>();
    test_empty<char *, int>();
    test_empty<int, std::string>();

    std::cout <<  "empty: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_size()
{
    ft::map<T1, T2> a;

    assert(a.size() == 0);

    for (int i = 0; i < 50; i++)
        a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.size() == 1);

    a.erase(a.begin());
    assert(a.size() == 0);
}

static void size()
{
    test_size<char, int>();
    test_size<int, int>();
    test_size<float, char>();
    test_size<char *, int>();
    test_size<int, std::string>();

    std::cout <<  "size: " <<  "OK" << std::endl;
}

static void max_size()
{
    ft::map<char, int> a;

    a.max_size();

    std::cout <<  "max_size: " <<  "OK" << std::endl;
}

static void test_operator_access_practical()
{
    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 5));
    a.insert(ft::make_pair<char, int>('c', 5));
    a.insert(ft::make_pair<char, int>('d', 5));

    assert(a['a'] == 5);
    assert(a['b'] == 5);
    assert(a['c'] == 5);
    assert(a['d'] == 5);
    a['e'] = 10;
    assert(a['e'] == 10);

    assert(a.size() == 5);
    a['f'];
    assert(a.size() == 6);
    a['f'];
    assert(a.size() == 6);

    a['a'] = 10;
    assert(a['a'] == 10);

    a.insert(ft::make_pair<char, int>('a', 5));
    assert(a['a'] == 10);
}

template <typename T1, typename T2>
static void test_operator_access()
{
    ft::map<T1, T2> a;

    for (int i = 0; i < 50; i++)
        a[T1()] = T2();

    assert(a.size() == 1);

    assert((*(a.begin())).first == T1());
    assert((*(a.begin())).second == a[T1()]);
    assert(a[T1()] == T2());
}

static void operator_access()
{
    test_operator_access_practical();
    test_operator_access<char, int>();
    test_operator_access<int, int>();
    test_operator_access<float, char>();
    test_operator_access<char *, int>();
    test_operator_access<int, std::string>();

    std::cout <<  "operator[]: " <<  "OK" << std::endl;
}

static void test_insert_single_practical()
{
    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    assert(a.size() == 1);
    a.insert(ft::make_pair<char, int>('a', 5));
    assert(a.size() == 1);
    a.insert(ft::make_pair<char, int>('a', 999));
    assert(a.size() == 1);
    a.insert(ft::make_pair<char, int>('b', 0));
    assert(a.size() == 2);
}

static void test_insert_range_practical()
{
    ft::map<char, int> a;

    a.insert(ft::make_pair<char, int>('a', 5));
    a.insert(ft::make_pair<char, int>('b', 6));
    a.insert(ft::make_pair<char, int>('c', 5));
    a.insert(ft::make_pair<char, int>('d', 6));

    assert(a.size() == 4);

    ft::map<char, int> b;

    b.insert(a.begin(), a.end());

    assert(b.size() == 4);
    b.insert(a.begin(), a.end());
    assert(b.size() == 4);
}

static void test_insert_hint_practical()
{
    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 5));

    assert(a.size() == 1);
    a.insert(a.begin(), ft::make_pair<char, int>('a', 6));
    assert(a.size() == 1);

    a.insert(a.begin(), ft::make_pair<char, int>('b', 6));
    assert(a.size() == 2);
}

static void test_insert_practical()
{
    test_insert_single_practical();
    test_insert_range_practical();
    test_insert_hint_practical();
}

template <typename T1, typename T2>
static void test_insert()
{
    ft::map<T1, T2> a;
    ft::map<T1, T2> empty;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.size() == 1);
    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.size() == 1);

    ft::map<T1, T2> b;

    b.insert(empty.begin(), empty.end());
    assert(b.empty());

    b.insert(a.begin(), a.end());
    assert(b.size() == 1);

    b.insert(a.begin(), a.end());
    assert(b.size() == 1);
}

static void insert()
{
    test_insert_practical();
    test_insert<char, int>();
    test_insert<int, int>();
    test_insert<float, char>();
    test_insert<char *, int>();
    test_insert<int, std::string>();

    std::cout <<  "insert: " <<  "OK" << std::endl;
}

static void test_erase_practical()
{
    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    assert((*(a.begin())).first == 'a');
    assert(a.size() == 4);

    a.erase(a.begin());

    assert((*(a.begin())).first == 'b');
    assert((*(a.begin())).second == 2);

    a.erase(a.begin());

    assert((*(a.begin())).first == 'c');
    assert((*(a.begin())).second == 3);

    a.erase(a.begin());

    assert((*(a.begin())).first == 'd');
    assert((*(a.begin())).second == 4);
}

template <typename T1, typename T2>
static void test_erase()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    a.erase(a.begin());

    assert(a.empty());
    a.erase(a.begin());
    a.erase(a.end());
    assert(a.empty());
}

static void test_erase_key_practical()
{
    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    assert(a.erase('a') == 1);
    assert(a.erase('a') == 0);

    assert(a.erase('b') == 1);
    assert(a.erase('b') == 0);

    assert(a.erase('c') == 1);
    assert(a.erase('c') == 0);

    assert(a.erase('d') == 1);
    assert(a.erase('d') == 0);

    assert(a.erase('z') == 0);
    assert(a.empty());
}

template <typename T1, typename T2>
static void test_erase_key()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    assert(a.erase(T1()) == 1);

    assert(a.empty());
    assert(a.erase(T1()) == 0);
    assert(a.empty());
}

static void test_erase_range_practical()
{
    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    a.erase(a.begin(), ++a.begin());
    assert((*(a.begin())).first == 'b');
    assert((*(a.begin())).second == 2);

    a.erase(a.begin(), a.end());
    assert(a.empty());
}

template <typename T1, typename T2>
static void test_erase_range()
{
    ft::map<T1, T2> a;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));
    a.erase(a.begin(), a.end());

    assert(a.empty());
    a.erase(a.begin(), a.end());
    assert(a.empty());
}
static void erase()
{
    test_erase_practical();
    test_erase_range_practical();
    test_erase_key_practical();

    test_erase<char, int>();
    test_erase<int, int>();
    test_erase<float, char>();
    test_erase<char *, int>();
    test_erase<int, std::string>();

    test_erase_key<char, int>();
    test_erase_key<int, int>();
    test_erase_key<float, char>();
    test_erase_key<char *, int>();
    test_erase_key<int, std::string>();

    test_erase_range<char, int>();
    test_erase_range<int, int>();
    test_erase_range<float, char>();
    test_erase_range<char *, int>();
    test_erase_range<int, std::string>();

    std::cout <<  "erase: " <<  "OK" << std::endl;
}

static void test_swap_practical()
{
    ft::map<char, int> a;

    a.insert(a.begin(), ft::make_pair<char, int>('a', 1));
    a.insert(a.begin(), ft::make_pair<char, int>('b', 2));
    a.insert(a.begin(), ft::make_pair<char, int>('c', 3));
    a.insert(a.begin(), ft::make_pair<char, int>('d', 4));

    ft::map<char, int> b;

    a.swap(b);

    assert(b.size() == 4);
    assert(a.empty());

    assert((*(b.begin())).first == 'a');
    assert((*(++b.begin())).first == 'b');
    assert((*(--b.end())).first == 'd');
}

template <typename T1, typename T2>
static void test_swap()
{
    ft::map<T1, T2> a;
    ft::map<T1, T2> b;

    a.insert(ft::make_pair<T1, T2>(T1(), T2()));

    assert(a.size() == 1);
    assert((*(a.begin())).first == T1());
    assert((*(a.begin())).second == T2());
    assert((*(--a.end())).first == T1());
    assert((*(--a.end())).second == T2());
    assert(b.empty());

    a.swap(b);

    assert(b.size() == 1);
    assert((*(b.begin())).first == T1());
    assert((*(b.begin())).second == T2());
    assert((*(--b.end())).first == T1());
    assert((*(--b.end())).second == T2());
    assert(a.empty());
}

static void swap()
{
    test_swap_practical();
    test_swap<char, int>();
    test_swap<int, int>();
    test_swap<float, char>();
    test_swap<char *, int>();
    test_swap<int, std::string>();

    std::cout <<  "swap: " <<  "OK" << std::endl;
}

static void test_clear_practical()
{
    ft::map<char, int> a;

    for (int i = 0; i < 50; i++)
        a.insert(ft::make_pair<char, int>(i, i));

    assert(a.size() == 50);

    a.clear();

    assert(a.empty());
}

template <typename T1, typename T2>
static void test_clear()
{
    ft::map<T1, T2> a;

    a[T1()] = T2();
    assert(a.size() == 1);

    a.clear();

    assert(a.empty());

    a[T1()];
    assert(a.size() == 1);
    a.clear();
    assert(a.empty());
}

static void clear()
{
    test_clear_practical();
    test_clear<char, int>();
    test_clear<int, int>();
    test_clear<float, char>();
    test_clear<char *, int>();
    test_clear<int, std::string>();

    std::cout <<  "clear: " <<  "OK" << std::endl;
}

template <typename T1, typename T2>
static void test_find()
{
    ft::map<T1, T2> a;
    const ft::map<T1, T2> b;

    assert(a.find(T1()) == a.end());
    assert(b.find(T1()) == b.end());

    a[T1()];
    assert(a.size() == 1);
    assert(a.find(T1()) == a.begin());
    assert(a.find(T1()) == --a.end());

    assert(b.size() == 0);
    assert(b.find(T1()) == b.begin());
}

static void find()
{
    test_find<char, int>();
    test_find<int, int>();
    test_find<float, char>();
    test_find<char *, int>();
    test_find<int, std::string>();

    std::cout <<  "find: " <<  "OK" << std::endl;
}

static void test_count_practical()
{
    ft::map<char, int> a;

    for (int i = 0; i < 50; i++)
        a.insert(ft::make_pair<char, int>(i, i));

    for (int i = 0; i < 50; i++)
        assert(a.count(i) == 1);
    assert(a.count(50) == 0);

    a.clear();
    for (int i = 0; i < 50; i++)
        assert(a.count(i) == 0);
}

template <typename T1, typename T2>
static void test_count()
{
    ft::map<T1, T2> a;

    assert(a.count(T1()) == 0);
    a[T1()];
    assert(a.count(T1()) == 1);

    a.erase(a.begin());

    assert(a.count(T1()) == 0);
}

static void count()
{
    test_count_practical();
    test_count<char, int>();
    test_count<int, int>();
    test_count<float, char>();
    test_count<char *, int>();
    test_count<int, std::string>();

    std::cout <<  "count: " <<  "OK" << std::endl;
}

static void test_lower_bound_practical()
{
    ft::map<char, int> a;
    std::map<char, int> std_a;

    for (int i = 0; i < 50; i++)
    {
        a.insert(ft::make_pair<char, int>(i, i));
        std_a.insert(std::make_pair(i, i));
        assert((*(a.lower_bound(i))).first == i);
        assert((*(std_a.lower_bound(i))).first == i);
    }
    a.clear();
    std_a.clear();

    assert(a.lower_bound(char()) == a.end());
    assert(std_a.lower_bound(char()) == std_a.end());
    a['a'] = 20;
    a['b'] = 40;
    a['c'] = 60;
    a['d'] = 80;
    a['e'] = 100;
    a['g'] = 120;

    std_a['a'] = 20;
    std_a['b'] = 40;
    std_a['c'] = 60;
    std_a['d'] = 80;
    std_a['e'] = 100;
    std_a['g'] = 120;

    assert(std_a.lower_bound('b') == ++std_a.begin());
    assert(std_a.lower_bound('f') == --std_a.end());
    assert((*(std_a.lower_bound('f'))).first == 'g');
    assert((*(std_a.lower_bound('f'))).second == 120);

    assert(a.lower_bound('b') == ++a.begin());
    assert(a.lower_bound('f') == --a.end());
    assert((*(a.lower_bound('f'))).first == 'g');
    assert((*(a.lower_bound('f'))).second == 120);

    const ft::map<char, int> b = a;

    assert(b.lower_bound('b') == ++b.begin());
    assert(b.lower_bound('f') == --b.end());
    assert((*(b.lower_bound('f'))).first == 'g');
    assert((*(b.lower_bound('f'))).second == 120);
}

template <typename T1, typename T2>
static void test_lower_bound()
{
    ft::map<T1, T2> a;
    std::map<T1, T2> std_a;

    assert(a.lower_bound(T1()) == a.end());
    assert(std_a.lower_bound(T1()) == std_a.end());
    a[T1()];
    std_a[T1()];

    assert(a.lower_bound(T1()) == a.begin());
    assert((*(a.lower_bound(T1()))).first == T1());
    assert((*(a.lower_bound(T1()))).second == T2());

    assert(std_a.lower_bound(T1()) == std_a.begin());
    assert((*(std_a.lower_bound(T1()))).first == T1());
    assert((*(std_a.lower_bound(T1()))).second == T2());

    const ft::map<T1, T2> b(a);

    assert(b.lower_bound(T1()) == b.begin());
    assert((*(b.lower_bound(T1()))).first == T1());
    assert((*(b.lower_bound(T1()))).second == T2());
}

static void lower_bound()
{
    test_lower_bound_practical();
    test_lower_bound<char, int>();
    test_lower_bound<int, int>();
    test_lower_bound<float, char>();
    test_lower_bound<char *, int>();
    test_lower_bound<int, std::string>();

    std::cout <<  "lower_bound: " <<  "OK" << std::endl;
}

static void test_upper_bound_practical()
{
    ft::map<char, int> a;
    std::map<char, int> std_a;

    for (int i = 0; i < 50; i++)
    {
        a.insert(ft::make_pair<char, int>(i, i));
        std_a.insert(std::make_pair(i, i));
        assert(a.upper_bound(i) == a.end());
        assert(std_a.upper_bound(i) == std_a.end());
    }
    a.clear();
    std_a.clear();

    assert(a.upper_bound(char()) == a.end());
    assert(std_a.upper_bound(char()) == std_a.end());
    a['a'] = 20;
    a['b'] = 40;
    a['c'] = 60;
    a['d'] = 80;
    a['e'] = 100;
    a['g'] = 120;

    std_a['a'] = 20;
    std_a['b'] = 40;
    std_a['c'] = 60;
    std_a['d'] = 80;
    std_a['e'] = 100;
    std_a['g'] = 120;

    assert((*(std_a.upper_bound('a'))).first == 'b');
    assert((*(std_a.upper_bound('a'))).second == 40);
    assert((*(std_a.upper_bound('f'))).first == 'g');
    assert((*(std_a.upper_bound('f'))).second == 120);
    assert(std_a.upper_bound('g') == std_a.end());

    assert((*(a.upper_bound('a'))).first == 'b');
    assert((*(a.upper_bound('a'))).second == 40);
    assert((*(a.upper_bound('f'))).first == 'g');
    assert((*(a.upper_bound('f'))).second == 120);
    assert(a.upper_bound('g') == a.end());

    const ft::map<char, int> b = a;

    assert((*(b.upper_bound('a'))).first == 'b');
    assert((*(b.upper_bound('a'))).second == 40);
    assert((*(b.upper_bound('f'))).first == 'g');
    assert((*(b.upper_bound('f'))).second == 120);
    assert(b.upper_bound('g') == b.end());
}

template <typename T1, typename T2>
static void test_upper_bound()
{
    ft::map<T1, T2> a;
    std::map<T1, T2> std_a;

    assert(a.upper_bound(T1()) == a.end());
    assert(std_a.upper_bound(T1()) == std_a.end());
    a[T1()];
    std_a[T1()];

    assert(a.upper_bound(T1()) == a.end());

    assert(std_a.upper_bound(T1()) == std_a.end());
    const ft::map<T1, T2> b(a);

    assert(b.upper_bound(T1()) == b.end());
}

static void upper_bound()
{
    test_upper_bound_practical();
    test_upper_bound<char, int>();
    test_upper_bound<int, int>();
    test_upper_bound<float, char>();
    test_upper_bound<char *, int>();
    test_upper_bound<int, std::string>();

    std::cout <<  "upper_bound: " <<  "OK" << std::endl;
}

static void test_equal_range_practical()
{
    ft::map<char, int> mymap;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;

    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = mymap.equal_range('b');

    assert(ret.first->first == 'b');
    assert(ret.first->second == 20);
    assert(ret.second->first == 'c');
    assert(ret.second->second == 30);

    ret = mymap.equal_range('c');

    assert(ret.first->first == 'c');
    assert(ret.first->second == 30);
    assert(ret.second == mymap.end());

    mymap['e'] = 50;

    ret = mymap.equal_range('d');

    assert(ret.first->first == 'e');
    assert(ret.first->second == 50);
    assert(ret.second->first == 'e');
    assert(ret.second->second == 50);
}

static void equal_range()
{
    test_equal_range_practical();

    std::cout <<  "equal_range: " <<  "OK" << std::endl;
}

int main()
{
    std::cout << "========= TEST FT::MAP =========" << std::endl;

    std::cout <<  "=== Constructors" << std::endl;
    default_constructor();
    range_constructor();
    copy_constructor();

    std::cout <<  "=== Assignement operator" << std::endl;
    assignement_operator();

    std::cout <<  "=== Iterators" << std::endl;
    begin_end();
    rbegin_rend();

    std::cout <<  "=== Capacity" << std::endl;
    empty();
    size();
    max_size();

    std::cout <<  "=== Element access" << std::endl;
    operator_access();

    std::cout <<  "=== Modifiers" << std::endl;
    insert();
    erase();
    swap();
    clear();
    
    std::cout <<  "=== Operations" << std::endl;
    find();
    count();
    lower_bound();
    upper_bound();
    equal_range();

    return (0);
}