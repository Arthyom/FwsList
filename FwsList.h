#ifndef FWSLIST_H
#define FWSLIST_H

    /************************************************************************************************/
    /******************************** libreria generica, lista enlazada *****************************/
    /************************************************************************************************/

    # include "FwsNoode.h"

/************************************************************************************************/
/******************************** definir el tipo FwsLista          *****************************/
/************************************************************************************************/

    typedef struct {

        FwsNode * listaInicio;
        int       dims;

    }FwsList;

/************************************************************************************************/
/******************************** funciones para crear y agregar nd *****************************/
/************************************************************************************************/

    FwsList     *   FwsListCrear     ( ){

        FwsList * nuevaLista = (FwsList*) malloc(sizeof(FwsList));
        nuevaLista->dims = 0;
        nuevaLista->listaInicio = NULL;

        return nuevaLista;
    }

    void            FwsListAddInicio ( FwsNode * nodoEntrada, FwsList * listaEntrada ){

        //conectar el nodo entrada con el el primer elemento de la lista
        FwsNodeCnctNodo(nodoEntrada, listaEntrada->listaInicio );
        listaEntrada->listaInicio = nodoEntrada;
        listaEntrada->dims++;
    }

    void            FwsListAddFinal  ( FwsNode * nodoEntrada, FwsList * listaEntrada ){

        // recorrer toda la lista hasta llegar al final y conectar con el ulimo nodo
        FwsNode * nodoAux = listaEntrada->listaInicio;

        if ( listaEntrada->listaInicio )
            FwsListAddInicio(nodoEntrada,listaEntrada->listaInicio);
        else
        {
            while (nodoAux->nodeSiguiente)
                nodoAux = nodoAux->nodeSiguiente;
            FwsNodeCnctNodo(nodoEntrada,nodoAux);

        }

        listaEntrada->dims ++;
    }


/************************************************************************************************/
/******************************** funciones para crear y agregar nd *****************************/
/************************************************************************************************/

    void            FwsListPrintInt  ( FwsList * listaEntrada ){
        FwsNode * nodoAux = listaEntrada->listaInicio;

        while(nodoAux){
            printf(" %d ->", (int) *nodoAux->nodeValue);
            nodoAux = nodoAux->nodeSiguiente;
        }
    }

#endif // FWSLIST_H
