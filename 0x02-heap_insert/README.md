<h1 class="gap">0x02. Heap Insert</h1>

<h2>Requirements</h2>

<h3>General</h3>

<ul>
<li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li>
<li>All your files will be compiled on Ubuntu 14.04 LTS</li>
<li>Your programs and functions will be compiled with <code>gcc 4.8.4</code> using the flags <code>-Wall</code> <code>-Werror</code> <code>-Wextra</code> and <code>-pedantic</code></li>
<li>All your files should end with a new line</li>
<li>A <code>README.md</code> file, at the root of the folder of the project, is mandatory</li>
<li>Your code should use the <code>Betty</code> style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl" title="betty-style.pl" target="_blank">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl" title="betty-doc.pl" target="_blank">betty-doc.pl</a></li>
<li>You are not allowed to use global variables</li>
<li>No more than 5 functions per file</li>
<li>You are allowed to use the standard library</li>
<li>In the following examples, the <code>main.c</code> files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own <code>main.c</code> files at compilation. Our <code>main.c</code> files might be different from the one shown in the examples</li>
<li>The prototypes of all your functions should be included in your header file called <code>binary_trees.h</code></li>
<li>Don’t forget to push your header file</li>
<li>All your header files should be include guarded</li>
</ul>

<h2>More Info</h2>

<h3>Data structures</h3>

<p>Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.</p>

<h4>Basic Binary Tree</h4>

<pre><code>/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
</code></pre>

<h4>Max Binary Heap</h4>

<pre><code>typedef struct binary_tree_s heap_t;
</code></pre>

<h3>Print function</h3>

<p>To match the examples in the tasks, you are given <a href="https://github.com/holbertonschool/0x1C.c" title="this function" target="_blank">this function</a></p>

<p>This function is used only for visualisation purpose. You don’t have to push it to your repo. It may not be used during the correction</p>

</div>


      

      

        
<h2 class="gap">Tasks</h2>


<div data-role="task3557" data-position="1" id="task-num-0">
<div class="panel panel-default task-card " id="task-3557">
  <span id="user_id" data-id="1875"></span>

  <div class="panel-heading">
    <h3 class="panel-title">
      0. New node
    </h3>
  </div>

  <div class="panel-body">
    <span id="user_id" data-id="1875"></span>

<ul>
<li>Prototype: <code>binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);</code></li>
<li><code>parent</code> is a pointer to the parent node of the node to create</li>
<li><code>value</code> is the value to put in the new node</li>
<li>When created, a node does not have any children</li>
<li>Your function must return a pointer to the new node, or <code>NULL</code> on failure</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 0-main.c 
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree-&gt;left);
        _binary_tree_delete(tree-&gt;right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 16);

    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
</code></pre>

  </div>

<div class="panel-heading">
    <h3 class="panel-title">
      1. Heap - Insert
    </h3>
  </div>

  <div class="panel-body">
    <span id="user_id" data-id="1875"></span>


<ul>
<li>Prototype: <code>heap_t *heap_insert(heap_t **root, int value);</code></li>
<li><code>root</code> is a double pointer to the root node of the Heap</li>
<li><code>value</code> is the value to store in the node to be inserted</li>
<li>Your function must return a pointer to the inserted node, or <code>NULL</code> on failure</li>
<li>If the address stored in <code>root</code> is <code>NULL</code>, the created node must become the root node.</li>
<li>You have to respect a <code>Max Heap</code> ordering</li>
<li>You are allowed to have up to <code>6</code> functions in your file</li>
</ul>

<p>Your file <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 1-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree-&gt;left);
        _binary_tree_delete(tree-&gt;right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&amp;root, 98);
    printf("Inserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 402);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 12);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 46);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 128);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 256);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 512);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 50);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}

alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
alex@/tmp/binary_trees$ ./1-heap_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
alex@/tmp/binary_trees$
</code></pre>

  </div>
