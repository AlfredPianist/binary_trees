#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a child to the right of the parent's
 *                            node. If the parent already has a right child,
 *                            this child will be the current node's right
 *                            child.
 *
 * @parent: Parent node.
 * @value: New node's value.
 *
 * Return: The new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_child;

	if (!parent)
		return (NULL);

	new_right_child = malloc(sizeof(*new_right_child));
	if (!new_right_child)
		return (NULL);

	new_right_child->left = new_right_child->right = NULL;

	if (parent->right)
	{
		new_right_child->right = parent->right;
		new_right_child->right->parent = new_right_child;
	}
	parent->right = new_right_child;

	new_right_child->parent = parent;
	new_right_child->n = value;

	return (new_right_child);
}
