# Memory Check using Valgrind

Valgrind is a memory mismanagement detector. It shows you memory leaks, deallocation errors, etc. Actually, Valgrind is a wrapper around a collection of tools that do many other things (e.g., cache profiling); however, here we focus on the default tool, memcheck.

### Usage:

```
valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose <executable>
```

### Useful links to learn:

- https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks
- https://www.cprogramming.com/debugging/valgrind.html
- http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
- https://valgrind.org/docs/manual/quick-start.html (Valgrind Documentation)

