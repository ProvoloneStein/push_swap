## push_swap

push_swap is a School 42 project. The goal of this project is create sorting algorithm with a limited list of operations.

[push_swap.en.pdf](/push_swap.en.pdf) is the task file.

## How to run?

``` 
./checker 2 1 3
sa
OK
```

checker program check is stack sorted after all operations you made.

```
./push_swap 2 1 3
sa
```

push_swap program output sorting operations

```
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG
OK
or
./push_swap 2 1 3 | ./checker 2 1 3
OK
```

-viz flag open debug menu in Terminal
-open flag write output in file

## Wiki

This project has small theory guide. This guide was written **in Russian**

You can read it [at the wiki-pages](../../wiki/).
