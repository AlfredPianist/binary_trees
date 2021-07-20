#include "binary_trees.h"

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - Retrieves a node's uncle.
 *
 * @tree: The node of the tree to retrieve its uncle.
 *
 * Return: pointer to uncle node, NULL otherwise or if parent is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (0);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Retrieves a node's sibling.
 *
 * @tree: The node of the tree to retrieve its sibling.
 *
 * Return: pointer to sibling node, NULL otherwise or if parent is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (0);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
