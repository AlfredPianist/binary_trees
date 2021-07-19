#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks if is a leaf
 * @node: node
 * Return: 0 - false,  1 - true
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}