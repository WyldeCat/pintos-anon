#ifndef __LIB_KERNEL_BINTREE_H
#define __LIB_KERNEL_BINTREE_H

/* Binary tree.

   This is implementation of a binary tree does not require
   use of dynamically allocated memory.
*/

#include <stddef.h>
#include <stdint.h>

/* Binary tree's node. */
struct bintree_node
  {
    struct bintree_node *parent;
    struct bintree_node *left;
    struct bintree_node *right;
  };

/* Binary tree. */
struct bintree
  {
    struct bintree_node *root;
    struct bintree_node *last_child;
  };

#define bintree_entry(BINTREE_NODE, STRUCT, MEMBER)     \
        ((STRUCT *) ((uint8_t *) BINTREE_NODE           \
                     - offsetof (STRUCT, MEMBER)))

/* Binary tree insertion. */
void bintree_push (struct bintree *, struct bintree_node *);

/* Binary tree removal. */
void bintree_remove (struct bintree *, struct bintree_node *);
void bintree_pop (struct bintree *, struct bintree_node *);

/* Binary tree nodes. */
struct bintree_node *bintree_root (struct bintree *);
struct bintree_node *bintree_last_child (struct bintree *);

/* Binary tree properties. */
bool bintree_empty (struct bintree *);

/* Miscellaneous */
void bintree_swap_nodes (struct bintree_node *, struct bintree_node *)

#endif
