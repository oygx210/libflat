#include <stddef.h>

#ifdef __linux__
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})
#else
#ifdef _WIN32
#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )
#endif
#endif

#include "interval_tree.h"
#include "interval_tree_generic.h"

#define START(node) ((node)->start)
#define LAST(node)  ((node)->last)

INTERVAL_TREE_DEFINE(struct interval_tree_node, rb,
		     unsigned long, __subtree_last,
		     START, LAST,, interval_tree)
