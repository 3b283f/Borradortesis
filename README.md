# Como generar pdf
```
pandoc -s Laura-Petrarch.md -o Laura-Petrarch.pdf
```

Para checar una ecuación por separado

```
pdflatex ecuacion.tex

```

Acuerdate de incluir el (esto solo es necesario si no se hace uso de una plantilla)

```
\documentclass{article}

\begin{document}

Aquí va el código de la ecuación

\end{document}

```
Para checar una ecuación desde la terminal
```
pandoc -s ecuación.tex --template=default.latex-- -o salida.pdflatex

```
Para escribir una palabra en negritas:
**Frederic Jones**

Este texto es en _CURSIVA_ O *ESTO*

Las viñetas son así:
* una
* nueva

Insertar un código.
```
System.out.print("Ejemplo")

```

Para insertar una imagen

![Description](images/index.jpeg)

Para hacer las ecuaciones, primero hacerlas individualmente en un archivo y después insertarlas donde sea necesario, mediante una instrucción
