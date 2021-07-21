#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 *
 * @parent: Parent node.
 * @value: New node's value.
 *
 * Return: The new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	return (new_node);
}
