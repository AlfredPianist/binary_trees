#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t countnode = 0;

	if (!tree || !(tree->left || tree->right))
		return (0);

	countnode = 1 + binary_tree_size(tree->right) + binary_tree_size(tree->left);
	return (countnode);
}
