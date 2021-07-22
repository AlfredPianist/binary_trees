#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if id full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 0;
	if (tree == NULL)
		return(0);
	
	if((tree->left == NULL && tree->right == NULL))
		return (1);

	is_full = binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
	return(is_full);
}