---
output:
    pdf_document: default
    html_document: default
---

# SLOW-FAST LIMIT CYCLES #

Para analizar desde este enfoque el sistema de Laura-Petrarch, se reescribe el modelo modificando la tercera ecuación que describe la inspiración de Pertarch, de la siguiente manera:

```{r child='EcuacionesLP/ec_per.tex'}
```

Donde los nuevos parámetros son positivos, siendo $\epsilon = \alpha_{3}$ y $\mu = \frac{\beta_{3}}{\alpha_{3}}$. Esto con el objetivo de derivar las condiciones generales en  los parámetros que garantizan la **existencia de ciclo límite**.

Si $\epsilon$ es pequeña la variable $I_{P}(t)$ es lenta con respecto a $L(t)$ y $P(t)$ de manera que se puede usar el método de perturbación singular. Este método afirma que el sistema se puede descomponer en componentes **rápidos** y **lentos**.
En este caso el subsistema rápido esta compuesto por las primeras dos ecuaciones con $I_{P} = cte$, mientras que el subsistema lento es solo la tercera ecuación.Tal descomposición permite construir órbitas singulares compuestas de concatenaciones de transiciones rápidas y lentas alternativas.

El principal resultado de la teoría de perturbación singular es que, bajo supuestos de regularidad adecuados, cualquier órbita del sistema se aproxima, para $\epsilon = 0$, la órbita singular correspondiente. 

## The fast subsystem ##
Las primeras dos ecuaciones con $I_{P} = cte$ describen la dinámica rápida del sistema. El estado $(L(t), P(t))$ de dicho sistema no puede tender hacia un cíclo límite ya que la divergencia es negativa (*Criterio de Dulac*). Así, L(t) y P(t) tienden hacia un equilibrio, hacia una solución constante (L,P) de estas dos ecuaciones. 

Al eliminar L de la primera ecuación, la segunda con $\frac{dL(t)}{dt} = \frac{dP(t)}{dt} = 0$ y separando las variable P y $I_{P}$, se obtiene la ecuación

\begin{equation}
 \Phi(I_{P}) = \Psi(P)
\end{equation}

Donde 

```{r child='EcuacionesLP/ec_nc.tex'}
```
con

```{r child='EcuacionesLP/ec_cnc.tex'}
```
Si $\Delta$ es positivo, es decir, si 

\begin{equation}
 \beta_{L}\beta_{P} > \alpha_{L}\alpha_{P}
\end{equation} \

La función $\Psi(P)$ tiene un mínimo en $\Psi^{-} = -2\Delta\sqrt{\Delta}$ en el punto $P^{-} = -\sqrt{\Delta}[P^{+} = \sqrt{\Delta}]$.

Al graficar la función $\Psi(P)$ y $\Phi(I_{P})$, esta última con los valores extremos de la inspiración poética $I_{P} = 0$, $I_{P} = \infty$, se cumple el caso en el que se mantienen las dos desigualdades entre los parámetros:

```{r child='EcuacionesLP/ec_par.tex'}
```

Bajo estas condiciones, $\Phi(I_{P}) = \Psi(P)$, tiene una **única y positiva** (negativa) solución **P** para 

$$0 \leq I_{P} < I_{P}^{-} [I_{P} > I_{P}^ {+}]$$


Siendo $I_{P}^{-} [I_{P}^{+}]$ el valor de $I_{P}$ para el que $\Phi(I_{P}^{-}) = \Psi^{-} [\Phi(I_{P}^{+}) = \Psi^{+}]$.

Por otro lado, en el intervalo $(I_{P}^{-}, I_{P}^{+})$, $\Phi(I_{P}) = \Psi(P)$, tiene tres soluciones. El valor de **equilibrio** esta dado por: 


Así cuando se satisfacen las condiciones (8) y el valor para el parámetro $A_{L}$ (10), **el subsistema rápido tiene un equilibrio único** para pequeños $(I_{P} < I_{P}^{-})$ y para altos $(I_{P} > I_{P}^{+})$ valores de la inspiración poética y **tres equilibrios** para valores intermedios $(I_{P}^{-} < I_{P} < I_{P}^{+})$. 

Al estudiar la estabilidad de estos equilibrios mediante la matriz Jacobiana, el resultado es que el equilibrio con $P^{-} < P < P^{+}$ es **inestable** mientras que las otras dos son **estables**. *Al equilibrio de el subsistema rápido*, para el que se cumple $I_{P} = \bar{I_{P}}$, es llamado **equilibrio manifold** de el subsistema rápido $\mu$. 

## Singular orbits and slow-fast limit cycles ##
Para este caso ahora se considera la componente lenta del sistema, que es la inspiración poética de Petrarch $I_{P}$, descrita por la tercera ecuación del modelo dado al inicio, con **$\epsilon$ pequeña y positiva**. En el espacio tridimensional $(L, P, I_{P})$ el manifold $\frac{dZ}{dt} = 0$ en el plano 
$$ I_{P} = \mu P$$

Para $\mu$ mayor que un valor crítico $\mu_{crit}$, tal plano se *separa* del equilibrio manifold en dos ramas, una superior ($\mu^{+}$) y otra inferior ($\mu^{-}$), de el subsistema rápido. El valor crítico de $\mu$ es $\frac{I_{P}^{+}}{P^{+}}$ donde $I_{P}^{+}$ es la solución de $\Phi(I_{P}) = \Psi(P)$ con $P = P^{+}$. Ahora tomando en cuenta el valor de $\Phi(I_{P})$, $P^{+} = \sqrt\Delta$ y $\Psi(P^{+}) = 2\Delta\sqrt\Delta$, se obtiene que:

```{r child='EcuacionesLP/ec_mcrit.tex'}
```

De manera que la órbita singular ocurre de dos maneras diferentes, ambas comenzando desde el origen:
$$\mu < \mu_{crit}$$
$$\mu > \mu_{crit}$$

El resultado de la teoría de perturbación singular se puede resumir mediante el siguiente teorema.

**TEOREMA**. *Si las condiciones (8)-(10) y $\epsilon$ es suficientemente pequeña, el sistema (1), (2), (3) tiene un atractor que es un equilibrio si $\mu < \mu_{crit}$ y un ciclo límite si $\mu > \mu_{crit}$. Además el ciclo límite tiende para $\epsilon\rightarrow 0$ a un ciclo singular límite.* 

- Si $\mu < \mu_{crit}$ pero $\epsilon$ no es pequeña, no hay garantía de que el ciclo límite se asemeje al ciclo singular límite.
- Si $\epsilon = 0.001$ el carácter rápido-lento del ciclo límite es claramente reconocible.
- Si $\epsilon = 0.1$ la transición rapida ya no es detectable.
- Si $\epsilon$ incrementa aún más, el ciclo límite podría incluso desaparecer, mediante una **Bifurcación Hopf Supercrítica** (única bifurcación detectada númericamente). Está bifurcación comienza del punto $\mu_{crit}$ en el eje vertical y es ortogonal a él en este punto. 

Se localiza un punto R, utilizando el conjunto de parámetros de valores:

\begin{tabular}{l c r}
    $\alpha_{L} = 3.6$,  &  $\alpha_{P} = 1.2$,  &  $\alpha_{IP} = 0.12$,  \\
    $\beta_{L} = 1.2$,  &  $\beta_{P} = 6$,  &  $\beta_{IP} = 12$, \\
    $\varUpsilon = \delta = 1$,  &  $A_{L} = 2$,  &   $A_{P} = -1$.
\end{tabular}

*Ahora empezando de este punto y decreciendo $\beta_{IP}$ (decrece $\mu = \frac{\beta_{IP}}{\alpha_{IP}}$) o incrementando $\alpha_{IP}$ (incrementa $\epsilon = \alpha_{IP}$ y decrece $\mu = \frac{\beta_{IP}}{\alpha_{IP}}$), el ciclo límite se encoge y desaparece.*














  


