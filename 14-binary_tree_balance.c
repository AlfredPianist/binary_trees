#include "binary_trees.h"

size_t binary_tree_height_2(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *                       from a given node (difference between the left
 *                       child's height and the right child's height)
 *
 * @tree: The node of the tree to calculate the balance factor.
 *
 * Return: the tree's balance factor, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height_2(tree->left) -
		binary_tree_height_2(tree->right));
}

/**
 * binary_tree_height_2 - Measures the height of a binary tree.
 *
 * @tree: The root of the tree to calculate its height.
 *
 * Return: the tree's height, 0 if tree is NULL.
 */
size_t binary_tree_height_2(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree)
		return (0);

	height_left = binary_tree_height_2(tree->left);
	height_right = binary_tree_height_2(tree->right);

	return (1 + (height_left >= height_right ? height_left : height_right));
}
