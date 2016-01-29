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

        if ( listaEntrada->listaInicio )
            //conectar el nodo entrada con el el primer elemento de la lista
            FwsNodeCnctNodoIn(nodoEntrada, listaEntrada->listaInicio );

        listaEntrada->listaInicio = nodoEntrada;
        listaEntrada->dims++;
    }

    void            FwsListAddFinal  ( FwsNode * nodoEntrada, FwsList * listaEntrada ){

        // recorrer toda la lista hasta llegar al final y conectar con el ulimo nodo
        FwsNode * nodoAux = listaEntrada->listaInicio;

        if ( !listaEntrada->listaInicio )
            FwsListAddInicio(nodoEntrada,listaEntrada->listaInicio);
        else
        {
            while (nodoAux->nodeSiguiente != NULL)
                nodoAux = nodoAux->nodeSiguiente;

            nodoAux->nodeSiguiente = nodoEntrada;
            nodoEntrada->nodoAnterior = nodoAux;

            FwsNodeCnctNodoFn(nodoEntrada,nodoAux);

        }

        listaEntrada->dims ++;
    }



/************************************************************************************************/
/******************************** funciones para crear y agregar nd *****************************/
/************************************************************************************************/

    void            FwsListPrintInt  ( FwsList * listaEntrada, int caso ){
        FwsNode * nodoAux = listaEntrada->listaInicio;

        while(nodoAux){

            switch (caso){

                case 1:  printf(" %d ->", *( (int*) nodoAux->nodeValue )); break;
                case 2:  printf(" %f ->", *( (float*) nodoAux->nodeValue )); break;
                case 3:  printf(" %c ->", *( (char*) nodoAux->nodeValue )); break;
                case 4:  printf(" %s ->", *( (char*) nodoAux->nodeValue )); break;

            }
            nodoAux = nodoAux->nodeSiguiente;
        }
        listaEntrada->dims++;
    }

#endif // FWSLIST_H
