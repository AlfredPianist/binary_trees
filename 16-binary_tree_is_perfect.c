#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_perfection(const binary_tree_t *tree,
			   size_t height, size_t level);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect or not (i.e.
 *                          each node has two nodes and its balance factor
 *                          is 0).
 *
 * @tree: The node of the tree to calculate its perfection.
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);

	return (binary_tree_perfection(tree, height, 0));
}

/**
 * binary_tree_perfection - Checks if a binary tree is perfect or not (i.e.
 *                          each node has two nodes and its balance factor
 *                          is 0), helper function.
 *
 * @tree: The node of the tree to calculate its perfection.
 * @height: The height of the whole tree.
 * @level: The current level.
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_perfection(const binary_tree_t *tree,
			   size_t height, size_t level)
{
	if (!tree)
		return (1);

	if (!(tree->left || tree->right))
		return (height == level + 1);

	if (!(tree->left && tree->right))
		return (0);

	return (binary_tree_perfection(tree->left, height, level + 1) &&
		binary_tree_perfection(tree->right, height, level + 1));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: The root of the tree to calculate its height.
 *
 * Return: the tree's height, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (1 + (height_left >= height_right ? height_left : height_right));
}
