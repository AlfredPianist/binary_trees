#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes that have at least a
 *                     child in a binary tree.
 *
 * @tree: The node of the tree to calculate the number of nodes.
 *
 * Return: the tree's nodes, 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || !(tree->right || tree->left))
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}
