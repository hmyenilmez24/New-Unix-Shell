# New-Unix-Shell

A sample unix shell which has been developed with C language to execute unix commands on MacOS.

There are two C files. One of them is shell_with_input_txt.c and the other one is shell.c

shell_with_input;_txt.c reads and executes commands which is taken from input.txt

shell.c executes commands which the user write

shell_with_input;_txt.c works with:

clang ~/shell_with_input_txt.c -o ~/shell_with_input_txt
./shell_with_input_txt.c shell ~/input.txt

shell.c works with:

clang ~/shell.c -o ~/shell
./shell.c

Also the user can execute shell.c with just clicking a compiled “shell” file.
