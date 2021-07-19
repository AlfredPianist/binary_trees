#include "binary_trees.h"
/**
 * binary_tree_insert_left - creates a new node in the left of a binary tree
 * @parent: parent node
 * @value: value into the new node
 * Return: new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		new_node->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
