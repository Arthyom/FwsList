#ifndef FWSNOODE_H
#define FWSNOODE_H

/************************************************************************************************/
/******************************** libreria generica, nodo X         *****************************/
/************************************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

    /****************************************************************************************/
    /***************************** declaracion del tipo FwsNode *****************************/
    /****************************************************************************************/
    typedef struct {

                   void    * nodeValue;
        struct     FwsNode * nodeSiguiente;
        struct     FwsNode * nodoAnterior;
                   int     * nodoEstado;
    }FwsNode;

    /****************************************************************************************/
    /**************************** prototipo y declaracion fngnrc ****************************/
    /****************************************************************************************/

    FwsNode *    FwNodeCrearNodo ( void * nodoValue ){

        FwsNode * nuevoNodo = (FwsNode*) malloc(sizeof(FwsNode));

        nuevoNodo->nodeValue     = nodoValue;
        nuevoNodo->nodeSiguiente = NULL;
        nuevoNodo->nodoAnterior  = NULL;
        nuevoNodo->nodoEstado    = 0;

        return nuevoNodo;

    }

    void    *    FwsNodeVistNodo ( FwsNode * nodoVisitar ){

        nodoVisitar->nodoEstado = 1;

    }

    void    *    FwsNodeCnctNodo ( FwsNode * nodoActual, FwsNode * nodoSiguiente ){
        // conectar al siguiente del actual con el siguiente
        nodoActual->nodeSiguiente = nodoSiguiente;

        // y al anterior del siguiente con el actual
        nodoSiguiente->nodoAnterior = nodoActual;
    }



#endif // FWSNOODE_H
