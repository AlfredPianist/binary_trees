#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses each node of a binary tree in postorder
 *                         (left - right - parent).
 *
 * @tree: The binary tree to be traversed.
 * @func: Pointer to function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
