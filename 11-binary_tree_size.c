#include "binary_trees.h"

/**
 * binary_tree_size - Measures the depth of a binary tree.
 *
 * @tree: The root of the tree to calculate its sizze.
 *
 * Return: the tree's size, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (1 + size);
}
