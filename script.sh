#!/bin/bash

R -e "rmarkdown::render('graficas.Rmd',output_file='graficas.pdf')"

#/usr/lib/rstudio/bin/pandoc/pandoc +RTS -K512m -RTS graficas.utf8.md --to latex --from markdown+autolink_bare_uris+tex_math_single_backslash --output graficas.tex  --include-in-header subtitle.tex --highlight-style tango --pdf-engine pdflatex --variable graphics --lua-filter /home/fismat/R/x86_64-pc-linux-gnu-library/3.5/rmarkdown/rmd/lua/pagebreak.lua --lua-filter /home/fismat/R/x86_64-pc-linux-gnu-library/3.5/rmarkdown/rmd/lua/latex-div.lua --variable 'geometry:margin=1in' --include-in-header compac-title.tex

#pdflatex graficas.tex
