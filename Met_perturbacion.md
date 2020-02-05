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

Si $\epsilon$ es pequeña la variable $Z(t)$ es lenta con respecto a $L(t)$ y $P(t)$ de manera que se puede usar el método de perturbación singular. Este método afirma que el sistema se puede descomponer en componentes **rápidos** y **lentos**.
En este caso el subsistema rápido esta compuesto por las primeras dos ecuaciones con $Z = cte$, mientras que el subsistema lento es solo la tercera ecuación.Tal descomposición permite construir órbitas singulares compuestas de concatenaciones de transiciones rápidas y lentas alternativas.

El principal resultado de la teoría de perturbación singular es que, bajo supuestos de regularidad adecuados, cualquier órbita del sistema se aproxima, para $\epsilon = 0$, la órbita singular correspondiente. 

## The fast subsystem ##
Las primeras dos ecuaciones con $Z = cte$ describen la dinámica rápida del sistema. El estado $(L(t), P(t))$ de dicho sistema no puede tender hacia un cíclo límite ya que la divergencia es negativa (*Criterio de Dulac*). Así, L(t) y P(t) tienden hacia un equilibrio, hacia una solución constante (L,P) de estas dos ecuaciones. 

Al eliminar L de la primera ecuación, la segunda con $\frac{dL(t)}{dt} = \frac{dP(t)}{dt} = 0$ y separando las variable P y Z, se obtiene la ecuación 

 $\Phi(Z) = \Psi(P)$

Donde 

```{r child='EcuacionesLP/ec_nc.tex'}
```
con
```{r child='EcuacionesLP/ec_cnc.tex'}
```
Si $\Delta$ es positivo, es decir, si 

$\beta_{L}\beta_{P} > \alpha_{L}\alpha_{P}$, 

  


