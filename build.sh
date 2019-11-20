#!/bin/bash

# Compilar la ecuacion 1
rm output/*.log
rm output/*.aux
rm output/*.pdf

pandoc -s EcuacionesLP/ec_1.tex --template=default.latex -o output/ec_1.pdf
pandoc -s EcuacionesLP/ec_2.tex --template=default.latex -o output/ec_2.pdf
pandoc -s EcuacionesLP/ec_3.tex --template=default.latex -o output/ec_3.pdf

pandoc -s Laura-Petrarch.md  -o output/Laura-Petrarch.pdf
