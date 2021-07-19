#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: s a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	int num = 0;

	if (tree != NULL && func != NULL)
	{
		num = tree->n;
		binary_tree_inorder(tree->left, func);
		func(num);
		binary_tree_inorder(tree->right, func);
		return;
	}
}
