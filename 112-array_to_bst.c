#include "binary_trees.h"

/**
 * array_to_bst - Converts to a Binary Search Tree.
 *
 * @array: The array to be converted to a BST.
 * @size: The size of the array.
 *
 * Return: pointer to root node in BST, NULL otherwise.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t counter;

	if (!array)
		return (NULL);

	for (counter = 0; counter < size; counter++)
		bst_insert(&root, array[counter]);

	return (root);
}
