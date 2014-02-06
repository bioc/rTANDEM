// stack standard header
// Originally written by see at the bottom.
// Modified by Attila Kertesz-Farkas at 2013.Jan.31

#pragma once
#ifndef _STACK_
#define _STACK_
#ifndef RC_INVOKED
#include <deque>
using namespace std;

#ifdef _MSC_VER
 #pragma pack(push,_CRT_PACKING)
 #pragma warning(push,3)
#endif  /* _MSC_VER */


		// TEMPLATE CLASS stack
template<class _Ty,
	class _Container = deque<_Ty> >
	class stack
	{	// LIFO queue implemented with a container
public:
	typedef _Container container_type;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;
	typedef typename _Container::reference reference;
	typedef typename _Container::const_reference const_reference;
	typedef typename _Container::iterator::pointer pointer;

	stack()
		: c()
		{	// construct with empty container
		}

	explicit stack(const _Container& _Cont)
		: c(_Cont)
		{	// construct by copying specified container
		}

	bool empty() const
		{	// test if stack is empty
		return (c.empty());
		}

	size_type size() const
		{	// test length of stack
		return (c.size());
		}

	reference top()
		{	// return last element of mutable stack
		return (c.back());
		}
	pointer access_top()
		{	// return mutable highest-priority element (retained)
		return (&c.back());
		}


	const_reference top() const
		{	// return last element of nonmutable stack
		return (c.back());
		}

	void push(const value_type& _Val)
		{	// insert element at end
		c.push_back(_Val);
		}

	void pop()
		{	// erase last element
		c.pop_back();
		}

	const _Container& _Get_container() const
		{	// get reference to container
		return (c);
		}

protected:
	_Container c;	// the underlying container
	};

		// stack TEMPLATE FUNCTIONS
template<class _Ty,
	class _Container> inline
	bool operator==(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test for stack equality
	return (_Left._Get_container() == _Right._Get_container());
	}

template<class _Ty,
	class _Container> inline
	bool operator!=(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test for stack inequality
	return (!(_Left == _Right));
	}

template<class _Ty,
	class _Container> inline
	bool operator<(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test if _Left < _Right for stacks
	return (_Left._Get_container() < _Right._Get_container());
	}

template<class _Ty,
	class _Container> inline
	bool operator>(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test if _Left > _Right for stacks
	return (_Right < _Left);
	}

template<class _Ty,
	class _Container> inline
	bool operator<=(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test if _Left <= _Right for stacks
	return (!(_Right < _Left));
	}

template<class _Ty,
	class _Container> inline
	bool operator>=(const stack<_Ty, _Container>& _Left,
		const stack<_Ty, _Container>& _Right)
	{	// test if _Left >= _Right for stacks
	return (!(_Left < _Right));
	}


#ifdef _MSC_VER
 #pragma warning(pop)
 #pragma pack(pop)
#endif  /* _MSC_VER */

#endif /* RC_INVOKED */
#endif /* _STACK_ */

/*
 * Copyright (c) 1992-2006 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Hewlett-Packard Company makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
 V5.02:0009 */
