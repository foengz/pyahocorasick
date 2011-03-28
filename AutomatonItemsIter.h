/*
	This is part of pyahocorasick Python module.
	
	AutomatonItemsIter const, struct & methods declarations.
	This class implements iterator walk over trie, that returns
	words and associated values. Object of this class is
	returned by 'keys'/'values'/'items' methods of Automaton class.

	Author    : Wojciech Mu�a, wojciech_mula@poczta.onet.pl
	WWW       : http://0x80.pl/proj/pyahocorasick/
	License   : 3-clauses BSD (see LICENSE)
	Date      : $Date$

	$Id$
*/
#ifndef ahocorasick_AutomatonItemsIter_h_included
#define ahocorasick_AutomatonItemsIter_h_included

#include "common.h"
#include "Automaton.h"

typedef enum {
	ITER_KEYS,
	ITER_VALUES,
	ITER_ITEMS
} ItemsType;


typedef struct AutomatonItemsIter {
	PyObject_HEAD

	Automaton*	automaton;
	int			version;		///< automaton version
	TrieNode* 	state;			///< current automaton node
	List		stack;			///< stack
	ItemsType	type;			///< type of iterator (KEYS/VALUES/ITEMS)
	
	size_t		n;				///< length of buffer
	char*		buffer;			///< buffer to construct key representation
} AutomatonItemsIter;


/* __init__() */
static PyObject*
automaton_items_iter_new(Automaton* automaton);

#endif
