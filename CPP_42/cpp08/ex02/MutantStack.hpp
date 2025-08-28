/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:46:58 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/09 01:09:54 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <algorithm>
# include <stack>
# include <list>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			c_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		r_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	cr_iterator;

	MutantStack(void): std::stack<T>() {};
	MutantStack(MutantStack const &inst): std::stack<T>(inst) {};
	~MutantStack() {};

	MutantStack	&operator=(MutantStack const &inst)
	{
		std::stack<T>::operator=(inst);
		return (*this);
	}

	iterator	begin(void) {return (std::stack<T>::c.begin());};
	c_iterator	begin(void) const {return (std::stack<T>::c.begin());};
	iterator	end(void) {return (std::stack<T>::c.end());};
	c_iterator	end(void) const {return (std::stack<T>::c.end());};

	r_iterator	rbegin(void) {return (std::stack<T>::c.rbegin());};
	cr_iterator	rbegin(void) const {return (std::stack<T>::c.rbegin());};
	r_iterator	rend(void) {return (std::stack<T>::c.rend());};
	cr_iterator	rend(void) const {return (std::stack<T>::c.rend());};
};

#endif
