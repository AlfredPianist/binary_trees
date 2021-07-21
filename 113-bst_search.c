#include "binary_trees.h"

/**
 * bst_search - Searches for a value on a Binary Search Tree.
 *
 * @tree: The BST to be searched upon.
 * @value: The value to be serched.
 *
 * Return: pointer to the node in BST that matches the value, NULL otherwise.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));

	return (NULL);
}
