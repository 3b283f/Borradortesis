#!/bin/bash

# Compilar la ecuacion 1
rm output/*.log
rm output/*.aux
rm output/*.pdf

pandoc -s EcuacionesLP/ec_1.tex --template=default.tex -o output/ec_1.pdf

pandoc -s Laura-Petrarch.md  -o output/Laura-Petrarch.pdf
