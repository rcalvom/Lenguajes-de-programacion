# **Analizador Léxico**

Proyecto en C++ con una implementación generalizada de un analizador léxico.

## **Uso:**
Este proyecto requiere los siguientes datos de entrada:
* ### **Palabras reservadas del lenguaje**
    Las palabras reservadas deben colocarse una en cada linea en el archivo *reserved_words.in* que puede ser encontrado en la carpeta *src*
* ### **Estados del autómata**
    Los estados deben ser identificados usando un número entero, seguidos por su aceptación: 1 como aceptación y 0 como no aceptación. Esto debe indicarse en el archivo *states.in* de la carpeta *src*.
* ### **Función de transición**
    La función de transición debe ser colocada en forma de tabla separada por espacios, la primera fila debe contener los encabezados los cuales son la representación en la codificación ASCII de cada uno de los simbolos. Esta información se debe mostrar en el archivo *src/delta.in*.

## **Ejemplo: Lenguaje PsiCoder**
* ### **Palabras reservadas del lenguaje**
    ```
    funcion_principal
    fin_principal
    booleano
    caracter
    entero
    real
    cadena
    leer
    imprimir
    si
    entonces
    si_no
    fin_si
    mientras
    hacer
    fin_mientras
    para
    fin_para
    seleccionar
    entre
    caso
    romper
    defecto
    fin_seleccionar
    estructura
    fin_estructura
    funcion
    fin_funcion
    retornar
    falso
    verdadero
    ```
* ### **Autómata**
    ![Automaton](./graph.svg)         