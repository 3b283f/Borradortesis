# Como generar pdf
```
pandoc -s Laura-Petrarch.md -o Laura-Petrarch.pdf
```

Para checar una ecuación por separado

```
pdflatex ecuacion.tex

```

Acuerdate de incluir el

```
\documentclass{article}

\begin{document}

Aqui va el codigo de la ecuacion

\end{document}

```
