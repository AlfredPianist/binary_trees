#include "binary_trees.h"

int check_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a BST or not (i.e.
 *                      A Binary Search Tree).
 *
 * @tree: The node of the tree to calculate if BST.
 *
 * Return: 1 if BST, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}

/**
 * check_bst - Checks if a binary tree is a BST or not (i.e.
 *             A Binary Search Tree).
 *
 * @tree: The node of the tree to calculate if BST.
 * @min: The minimum value to compare current node's value.
 * @max: The maximum value to compare current node's value.
 *
 * Return: 1 if BST, 0 otherwise.
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (check_bst(tree->left, min, tree->n - 1) &&
		check_bst(tree->right, tree->n + 1, max));
}
