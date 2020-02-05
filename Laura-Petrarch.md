---
output:
    pdf_document: default
    html_document: default
---

# Emociones de amor entre Laura y Petrarch #

Este sistema dinámico esta basado en el estudio de "el Cancionero", escrito por Francis Petrarch. Es una colección de 366 poemas sin orden cronológico y reflejan sus vivencias con
respecto a su amor por Laura. En ellos expresa tanto su amor extático como su desesperación
profunda, incluso hasta después de la muerte de esta. A pesar de que su amor nunca fue recíproco él le escribió más de 200 poemas durante casi 21 años.

**Frederic Jones**, hizo un estudio sobre los poemas, analizando uno por uno, con el objetivo de encontrar una manera de poder clasificarlos cronológicamente. Comenzó analizando 23 poemas de los que estaba seguro de su fecha.
Su análisis consistía en revisar cuidadosamente la lírica y lingüística de cada uno de ellos, para después poder asignarles grados, entre un rango de -1 a +1, donde el grado máximo era +1 y representaba el amor extático, mientras que los grados muy negativos corresponden a su profunda desesperación. A partir de esto, detecto un comportamiento oscilante al que llamo **ciclo emocional de Petrarch E(t)**. Al resto de los poemas,  de los que desconocía su fecha, los clasifico de manera que encajaran en este ciclo y así poder asignarles una fecha.

A partir de este estudio, que presento en 1995, en su libro titulado **"La estructura del Cancionero de Petrarch"**, S. Rinaldi trató de explicar su comportamiento mediante una serie de ecuaciones. Tomando en cuenta sus emociones, tales como la atracción, rechazo, abandono, inspiración, etc. Mediante parámetros con los que al aumentarlos
o disminuirlos se pudiera crear una amplia variedad de comportamiento emocional, debido a la no linealidad que presentan estos.

Para crear este modelo, se baso en una dinámica de tipo depredador-presa, esta estudia el crecimiento de dos poblaciones que interactúan, en este caso sería el comportamiento entre Laura L(t) y Petrarch P(t).

- $L(t)$ representa el amor de Laura por el poeta en un tiempo $t$. Valores positivos de L significan amistad cálida, mientras que valores negativos significan frialdad y antagonismo.  
- $P(t)$ representa el amor de Petrarch por Laura. Valores positivos significan amor extático, mientras que valores negativos significan desesperación.

A partir de esto obtuvo un modelo general, dado por dos EDO:

```{r child='EcuacionesLP/ec_1.tex'}
```

Donde cada una de estas ecuaciones se componía de tres términos diferentes:

- El primero, describe el proceso de olvido de cada individuo, por lo que le otorgaba un signo negativo.
- El segundo, es la reacción de uno de ellos con respecto al amor del otro.
- El tercero, es la respuesta a su atracción.

Sin embargo, se dio cuenta de que su modelo no estaba completo y agrego un termino más para la inspiración de Petrarch $I_{P}(t)$, que describe su productividad para crear los poemas influenciado por la atracción que siente hacia Laura. Además se dio cuenta de que las funciones de reacción no eran completamente no lineales, Por lo que agrego unos parámetros adicionales para completar cada una de las funciones de reacción, de la siguiente forma:

```{r child='EcuacionesLP/ec_2.tex'}
```

Cabe destacar, que en este nuevo sistema de ecuaciones,en la segunda ecuación, que representa el amor de Petrarch por Laura, el tercer término que corresponde a la respuesta de Petrarch a la atracción de Laura depende también de su inspiración $I_{P}$. La tercera ecuación que se agrega es la de la inspiración de Petrarch, lo que nos dice es que el amor de Petrarch sustenta su inspiración  
- Para la función de reacción de Petrarch, se observa en sus poemas que él reacciona de manera muy intensa a los signos más relevantes de antagonismo.
- Para la función de reacción  de Laura, analizando para diferentes valores de de P:
  - Cuando P>0, primero aumenta y después decrece.
  - Cuando P<0, es decir, para cuando el poeta desespera, Laura se comporta de manera inesperada, ya que cambia su actitud por un sentimiento de pena hacia Petrarch.  
  De manera que propone la función de reacción como una función cúbica.  

Sustituyendo estos términos en el último modelo, se obtiene las ecuaciones del **modelo completo**

```{r child='EcuacionesLP/ec_3.tex'}
```

El modelo completo de Laura-Petrarch se compone de:

**1. "3 constantes de tiempo":**

  - $\alpha_{L}$, proceso de olvido de Laura.
  - $\alpha_{P}$, proceso de olvido de Petrarch.
  - $\alpha_{IP}$, describe la forma en que se comporta la inspiración de Petrarch conforme pasa el tiempo.

Para estas siempre se debe cumplir que:

- **$\alpha_{L}$** **> $\alpha_{P}$**, ya que Laura nunca parece estar muy involucrada, mientras Petrarch parece siempre estar muy interesado.
- **$\alpha_{IP}$** **< $\alpha_{P}$**, debido a que la inspiración del poeta disminuye muy lentamente, ya que continua escribiendo por más de 10 años después de la muerte de Laura, pero ya no sobre su amor por Laura, sino acerca de su recuerdo y la forma en la que esperaba que la muerte llegará a él. Esto es:

- $\alpha_{L}$ ~ $3\cdot\alpha_{P}$,
- $\alpha_{P}$ ~ $10\cdot\alpha_{IP}$,
- $\alpha_{P}$ ~ $1$.

**2. "3 parámetros de reacción o ganancia":**

  - $\beta_{L}$,
  - $\beta_{P}$,
  - $\beta_{IP}$

Estas se pueden estimar cualitativamente con respecto a las contantes de tiempo. Así:

  - $\beta_{L}$ ~ $\alpha_{P}$, la reacción de Laura es igual al tiempo de olvido de Petrarch.
  - $\beta_{P}$ ~ $5\cdot\alpha_{P}$, la reacción de Petrarch es 5 veces más fuerte que su proceso de olvido.
  - $\beta_{IP}$ ~ $10\cdot\alpha_{P}$.
  - $\gamma_{L}$ y $\delta_{P}$ son normalizados a uno, por simplicidad.

**3. "2 parámetros de atracción":**  

 Significan cuanto resulta atractivo tanto física, como social e intelectualmente, el uno para el otro. Su elección es fundamental ya que determinan la no linealidad del modelo. Estos cumplen que:

 - $A_{L} > 0$, ya que Petrarch ama a Laura.
 - $A_{P} < 0$, ya que Petrarch no resulta del todo atractivo para Laura, es un joven interesado en la historia y las letras, al que se le otorga un cargo que lo lleva a viajar frecuentemente al lugar donde vive Laura, de hecho el primer poema que le escribe es hasta después de 3 meses de conocerla.

Por lo tanto, los valores que se le otorgan a estos parámetros son:

  - $A_{L}$ ~ $2$,
  - $A_{P}$ ~ $-1$.    
