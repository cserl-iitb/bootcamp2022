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
