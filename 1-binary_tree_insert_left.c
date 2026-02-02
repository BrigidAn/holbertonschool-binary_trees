#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;

	/* Update parent of old left child if it exists */
	if (parent->left)
		parent->left->parent = new_node;

	/* Attach new node as the left child of parent */
	parent->left = new_node;

	return (new_node);
}
