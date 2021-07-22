#include "binary_trees.h"

int check_avl(const binary_tree_t *tree, int min, int max);
size_t binary_tree_height_2(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 *                      (i.e. Adelson-Velsky and Landis tree which is a
 *                      type of self-balancing binary tree with its balance
 *                      factor between -1 and 1).
 *
 * @tree: The node of the tree to calculate if AVL.
 *
 * Return: 1 if AVL, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_avl(tree, INT_MIN, INT_MAX));
}

/**
 * check_avl - Checks if a binary tree is AVL or not (i.e.
 *             A Adelson-Velsky Landis tree).
 *
 * @tree: The node of the tree to calculate if AVL.
 * @min: The minimum value to compare current node's value.
 * @max: The maximum value to compare current node's value.
 *
 * Return: 1 if AVL, 0 otherwise.
 */
int check_avl(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	if (binary_tree_balance(tree) < -1 || binary_tree_balance(tree) > 1)
		return (0);

	return (check_avl(tree->left, min, tree->n - 1) &&
		check_avl(tree->right, tree->n + 1, max));
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
