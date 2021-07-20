#include "binary_trees.h"

size_t binary_tree_height_2(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect or not (aka
 *                          each node has two nodes and its balance factor
 *                          is 0).
 *
 * @tree: The node of the tree to calculate its perfection.
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_is_full(tree) && (binary_tree_balance(tree) == 0))
		return (1);
	return (0);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full or not (aka
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
