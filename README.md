<p aling="center">
    <img  src="https://blog.desdelinux.net/wp-content/uploads/2019/01/bash-logo.jpg" width="400" height="200">
</p>

# **_Simple Shell Project_**

In this repository you will find our version of a simple UNIX command interpreter: Shell.

## Man Page

* To see the shell manual you must execute this command.

```
man ./man_1_simple_shell
```
## Environment
```
 This project has been tested on `Ubuntu 14.06.6 LTS`
```
## 📁 - Files

| **NAME OF THE FILE** | CONTENT |
|---|---|
|[_README.md_](./README.md)| It contains all the information about the project and all its content.
|[_shell.h_](./shell.h)| Header where are the libraries, the structures and the different prototypes of the new functions.|
|[_main.c_](./main.c)| Main file where the prompt is located and most of the functions are called.|
|[_split.c_](./split.c)| File containing the function to cut into pieces the line you sent us and organize them as pointers to each string in the line.|
|[_register.c_](./register.c)| File in which the function to search for the existence of a command is found.|
|[_find_command.c_](./find_command.c)| File in which there are functions to handle the search for the commands.|
|[_get_error.c_](./get_error.c)| File in which the function to print the standard error in case of error.|
|[_execution.c_](./execution.c)| File in which the function to execute the path where the commands are located is found.|
|[_tools1.c_](./tools.c)| File 1 in which there are different secondary functions used for the operation of the main functions.|
|[_tools2.c_](./tools.c)| File 2 in which there are different secondary functions used for the operation of the main functions.|
|[_garbage_colection.c_](./garbage_colection.c)| File in which there are different functions used to free the memory allocated with malloc.|
|[_man_1_simple_shell_](./man_1_simple_shell)|man-page for the program  shell.|
|[_AUTHORS_](./AUTHORS)|  File in which the people who contributed to this project are listed. |

## Flowchart

Through this link you can find the flowchart where we explain how the program works:  <a href="https://miro.com/welcomeonboard/1yqrjFsKFskz7RDAhljwN6XcEDHDXSLPYGGVCgJXGxCyhILHZOj0TJQzbxpyBR86">Here</a>


## ¿How to compile?

- _Run that command on your console where the project is located._

```
gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o hsh && ./hsh
```

## Examples

#### *Example 0*
* Print Current Directory
```bash
$ pwd
/home/runner/simpleshell/magic
$
```
#### *Example 1*
* List Files
```bash
$ /bin/ls
AUTHORS    tools.c  register.c   register.c
environ.c  main.c   execution.c  shell.h
$
```
#### *Example 2*
* Error cases.
```bash
$ lt
lt: command not found
$
```
#### *Example 3*
* Error cases.
```bash
$ /bin/lm
/bin/lm: no such file or directory
$
```

## Authors
- [_Salomé Grisales_](https://github.com/aike-s) - sagrilo804@gmail.com
- [_Samuel Trujillo Rodriguez_](https://github.com/samutrujillo) - samueltrujillorodriguez@gmail.com
- [_Sergio Ramos_](https://github.com/Sergioarg) - sergio_ramos53@yahoo.com
