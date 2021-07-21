#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int check_completeness(const binary_tree_t *tree, size_t index, size_t size);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete or not
 *                           (i.e. all levels filled except the final one which
 *                           is filled from left to right).
 *
 * @tree: The node of the tree to calculate its completeness.
 *
 * Return: 1 if complete, 0 otherwise or if tree NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (check_completeness(tree, 0, size));
}

/**
 * check_completeness - The actual recursive function. Calculates the tree's
 *                      completeness using the relationship 2i + 1 for the next
 *                      left child and 2i + 2 for the next right child.
 *
 * @tree: The node of the tree to calculate its completeness.
 * @index: The node's current index.
 * @size: The tree's size (number of nodes).
 *
 * Return: 1 if complete, 0 otherwise.
 */
int check_completeness(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (check_completeness(tree->left, 2 * index + 1, size) &&
		check_completeness(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Counts the total number of nodes of a binary tree.
 *
 * @tree: The root of the tree to calculate its size.
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
