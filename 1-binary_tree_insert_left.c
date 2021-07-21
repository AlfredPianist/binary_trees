#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a child to the left of the parent's node.
 *                           If the parent already has a left child, this child
 *                           will be the current node's left child.
 *
 * @parent: Parent node.
 * @value: New node's value.
 *
 * Return: The new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_child;

	if (!parent)
		return (NULL);

	new_left_child = malloc(sizeof(*new_left_child));
	if (!new_left_child)
		return (NULL);

	new_left_child->left = new_left_child->right = NULL;

	if (parent->left)
	{
		new_left_child->left = parent->left;
		new_left_child->left->parent = new_left_child;
	}
	parent->left = new_left_child;

	new_left_child->parent = parent;
	new_left_child->n = value;

	return (new_left_child);
}
