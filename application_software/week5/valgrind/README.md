# Memory Check using Valgrind

Valgrind is a memory mismanagement detector. It shows you memory leaks, deallocation errors, etc. Actually, Valgrind is a wrapper around a collection of tools that do many other things (e.g., cache profiling); however, here we focus on the default tool, memcheck.

### Usage:

```
valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose <executable>
```

### Useful links to learn:

- https://stackoverflow.com/a/44989219  
  This pretty much covers all the essential with some useful examples
- https://www.cprogramming.com/debugging/valgrind.html  
  This is a good resource for debugging - follow the links in the related articles section for detailed explanations
- http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/messages.html  
  This is a good resource for understanding the different kinds of memory errors caught by Valgrind
- https://valgrind.org/docs/manual/quick-start.html  
  Valgrind Documentation

## Server with and without memory leaks

Test server present [here](./test_server_with_leaks.c) is present with memory leaks at two places. Its equivalent server free of memory leaks is [here](../test_server.c).

Try to run valgrind on this server and see if it detects any memory leaks.

It should detect two major memory leaks - one would be due to the malloc() call (memory not freed) and the other would be due to pthread_create() call (thread stack not cleaned up).  
Both are easily - first by using free() call to free the memory allocated by malloc() and second by using pthread_join() call to wait for the thread to finish or pthread_detach() to detach the thread after exiting.
