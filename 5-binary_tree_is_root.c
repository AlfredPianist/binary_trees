#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root or not.
 *
 * @node: The node to check if it's root.
 *
 * Return: 1 if leaf, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
