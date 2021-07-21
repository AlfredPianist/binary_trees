#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right.
 *         Source:
 *             https://webdocs.cs.ualberta.ca/~holte/T26/tree-rotation.html
 *
 * @tree: The root of the tree to be rotated.
 *
 * Return: The new tree's root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	short pivot_parent_child_dir;
	binary_tree_t *inside, *rotator, *pivot, *pivot_parent;

	if (!tree)
		return (NULL);

	pivot = tree;

	pivot_parent = pivot->parent ? pivot->parent : NULL;
	if (pivot_parent)
		pivot_parent_child_dir = pivot_parent->left == pivot ? 0 : 1;

	rotator = pivot->left;
	if (!rotator)
		return (tree);

	inside = rotator->right;

	pivot->left = inside;
	if (inside)
		inside->parent = pivot;

	rotator->right = pivot;
	pivot->parent = rotator;

	if (pivot_parent)
	{
		if (pivot_parent_child_dir == 0)
			pivot_parent->left = rotator;
		else
			pivot_parent->right = rotator;
	}
	rotator->parent = pivot_parent;

	return (rotator);
}
