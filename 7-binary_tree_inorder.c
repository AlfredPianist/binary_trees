#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses each node of a binary tree in inorder
 *                       (left - parent - right).
 *
 * @tree: The binary tree to be traversed.
 * @func: Pointer to function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
