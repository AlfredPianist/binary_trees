#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a given node is a leaf or not.
 *
 * @node: The node to check if it's leaf.
 *
 * Return: 1 if leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
}
