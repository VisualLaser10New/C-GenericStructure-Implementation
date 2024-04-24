# Generare una cazzo di libreria statica

### Compilare la libreria in obj
```sh
gcc -c libreria.c -o libreria.o
```

### Generare il file .a con link
Il file .a deve iniziare con lib e poi il nome vero del file
```sh
ar -rcs libReria.a *.o
```

### Compilare il file main inclusivo della libreria
Il file header, relativo al file libreria, prima compilato, deve essere chiamato dai file main

```sh
gcc main.c -L . -lReria -o main
```
- -L permette di specificare il percorso delle librerie
- -l permette di omettere il prefisso *lib* e il suffisso *.a* nel nome del file .a

### Eseguire il cazzo volante di programma

```sh
./main
```
