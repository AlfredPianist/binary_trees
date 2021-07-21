#include "binary_trees.h"

/**
 * bst_insert - Inserts a new node in a Binary Search Tree.
 *
 * @tree: The node of the tree be inserted in the BST.
 * @value: The value of the new node.
 *
 * Return: pointer to new node in BST, NULL otherwise or if value
 *         already exists.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = *tree;
	while (parent)
	{
		if (value == parent->n)
			return (NULL);
		if (value < parent->n)
		{
			if (parent->left)
				parent = parent->left;
			else
			{
				parent->left = (bst_t *)binary_tree_node(parent, value);
				return (parent->left);
			}
		}
		else
		{
			if (parent->right)
				parent = parent->right;
			else
			{
				parent->right = (bst_t *)binary_tree_node(parent, value);
				return (parent->right);
			}
		}
	}
	return (*tree);
}
