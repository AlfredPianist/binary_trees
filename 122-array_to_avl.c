#include "binary_trees.h"

/**
 * array_to_avl - Converts to a AVL tree.
 *
 * @array: The array to be converted to a AVL tree.
 * @size: The size of the array.
 *
 * Return: pointer to root node in AVL tree, NULL otherwise.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t counter;

	if (!array)
		return (NULL);

	for (counter = 0; counter < size; counter++)
		avl_insert(&root, array[counter]);

	return (root);
}
