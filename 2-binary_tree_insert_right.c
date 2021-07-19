#include "binary_trees.h"
/**
 * binary_tree_insert_right - creates a new node in the rightt of a binary tree
 * @parent: parent node
 * @value: value into the new node
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		new_node->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
