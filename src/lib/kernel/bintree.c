#include "bintree.h"
#include "../debug.h"

void
bintree_insert_left (struct bintree_node *parent, struct bintree_node *node)
{
  ASSERT (parent != NULL);
  parent->left = node;
}

void
bintree_insert_right (struct bintree_node *parent, struct bintree_node *node)
{
  ASSERT (parent != NULL);
  parent->right = node;
}

void
bintree_remove (struct bintree *tree, struct bintree_node *node)
{
  struct bintree_node *n;

  ASSERT (tree != NULL && node != NULL);
  
  if (node == bintree_root (tree))
    {
      tree->root = NULL;
      tree->last_child = NULL;
    }
  else if (node == bintree_last_child (tree)) 
    {
      tree->last_child = NULL;
    }

  if (node->parent == NULL)
    return;

  node->parent = NULL;
  if (node == node->parent->left)
    node->parent->left = NULL;
  else if (node == node->parent->right)
    node->parent->right = NULL;

  n = bintree_last_child (tree);
  while (n != NULL)
    {
      if (n->parent == node)
        {
          tree->last_child = NULL;
          break;
        }
      n = n->parent;
    }
}

struct bintree_node *
bintree_root (struct bintree *tree)
{
  ASSERT (tree != NULL);
  return tree->root;
}

struct bintree_node *
bintree_last_child (struct bintree *tree)
{
  ASSERT (tree != NULL);
  return tree->last_child;
}

bool
bintree_empty (struct bintree *tree)
{
  return bintree_root (tree) == NULL;
}

static inline void
swap_pointers (void **pa, void **pb)
{
  void *tmp;

  tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}

void
bintree_swap_nodes (struct bintree_node *na, struct bintree *ta,
                    struct bintree_node *nb, struct bintree *tb)
{
  ASSERT (na != NULL && nb != NULL); 
  ASSERT (ta != NULL && tb != NULL); 

  swap_pointers ((void **)&na->parent, (void **)&nb->parent);
  swap_pointers ((void **)&na->left, (void **)&nb->left);
  swap_pointers ((void **)&na->right, (void **)&nb->right);

  if (ta->root == na)
      ta->root = nb;
  if (tb->root == nb)
      tb->root = na;

  if (ta->last_child == na)
      ta->last_child = nb;
  if (tb->last_child == nb)
      tb->last_child = na;
}
