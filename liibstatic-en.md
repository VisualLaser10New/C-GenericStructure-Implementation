# Generate a fucking static library

### Compile the library in obj
```sh
gcc -c library.c -o library.o
```

### Generate the .a file with linking 
The .a file must begin with *lib* prefix and then the real file's name
```sh
ar -rcs libRary.a *.o
```
### Compile the main file including the library
The header file, relative to the library, just compiled, must be called by the main file
```sh
gcc main.c -L . -lRary -o main
```
- -L allows to specify the libraries path
- -l allows to omit the *lib* prefix and the *.a* suffix in the .a file name

### Execute the fucing flying program
```sh
./main
```