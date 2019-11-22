
# Sistema dinámico: Emociones de amor entre Laura y Petrarch #

Este sistema dinámico esta basado en el estudio de "el Cancionero", escrito por Francis Ptrarch. Es una colección de 366 poemas sin orden cronológico y reflejan sus vivencias con
respecto a su amor por Laura. En ellos expresa tanto su amor extático como su desesperación
profunda, incluso hasta después de la muerte de esta. A pesar de que su amor nunca fue recíproco él le escribió más de 200 poemas durante casi 21 años.

**Frederic Jones**, hizo un estudio sobre los poemas, analizando uno por uno, con el objetivo de encontrar una manera de poder clasificarlos cronológicamente. Comenzó analizando 23 poemas de los que estaba seguro de su fecha.
Su análisis consistía en revisar cuidadosamente la lírica y lingüística de cada uno de ellos, para después poder asignarles grados, entre un rango de -1 a +1, donde el grado máximo era +1 y representaba el amor extático, mientras que los grados muy negativos corresponden a su profunda desesperación. A partir de esto, detecto un comportamiento oscilante al que llamo **ciclo emocional de Petrarch E(t)**. Al resto de los poemas,  de los que desconocía su fecha, los clasifico de manera que encajaran en este ciclo y así poder asignarles una fecha.

A partir de este estudio, que presento en 1995, en su libro titulado **"La estructura del Cancionero de Petrarch"**, S. Rinaldi trató de explicar su comportamiento mediante una serie de ecuaciones. Tomando en cuenta sus emociones, tales como la atracción, rechazo, abandono, inspiración, etc. Mediante parámetros con los que al aumentarlos
o disminuirlos se pudiera crear una amplia variedad de comportamiento emocional, debido a la no linealidad que presentan estos.

Para crear este modelo, se baso en una dinámica de tipo depredador-presa, esta estudia el crecimiento de dos poblaciones que interactúan, en este caso sería el comportamiento entre Laura L(t) y Petrarch P(t).

- $L(t)$ representa el amor de Laura por el poeta en un tiempo $t$.
- $P(t)$ representa el amor de Petrarch por Laura.

A partir de esto obtuvo un modelo general, dado por dos EDO, donde cada una de estas ecuaciones se componía de tres términos diferentes:
- El primero, describe el proceso de olvido de cada individuo, por lo que le otorgaba un signo negativo.
- El segundo, es la reacción de uno de ellos con respecto al amor del otro.
- El tercero, es la respuesta a su atracción.

Sin embargo, se dio cuenta de que su modelo no estaba completo y agrego un termino más para la inspiración de Petrarch,que describe su productividad para crear los poemas influenciado por la atracción que siente hacia Laura.  
