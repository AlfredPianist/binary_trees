#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves from a node of a binary tree.
 *
 * @tree: The node of the tree to calculate its leaves.
 *
 * Return: the tree's leaves, 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->right || tree->left))
		return (1);

	return (binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right));
}
