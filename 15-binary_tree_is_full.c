#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full or not (i.e.
 *                       each node can't have only one child).
 *
 * @tree: The node of the tree to calculate its fullness.
 *
 * Return: 1 if full, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left || tree->right))
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
