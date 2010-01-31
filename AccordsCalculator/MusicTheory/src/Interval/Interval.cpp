#include "stdafx.h"
#include "Interval.h"


using namespace LibMusic;


Interval::Interval(
    size_t notesCount, 
    size_t halfTonesCount):
notesCount_     (notesCount    ),
halfTonesCount_ (halfTonesCount)
{
}


//////////////////////////////////////////////////////////
//               CONSTRUCTORS                           //
//////////////////////////////////////////////////////////
Interval Interval::CreatePrimoPure     ()
{
    return Interval(0, PRIMO);
}


Interval Interval::CreateSecundaSmall  ()
{
    return Interval(1, SECUNDA_SMALL);
}


Interval Interval::CreateSecundaLarge  ()
{
    return Interval(1, SECUNDA_LARGE);
}


Interval Interval::CreateTerciaSmall   ()
{
    return Interval(2, TERCIA_SMALL);
}


Interval Interval::CreateTerciaLarge   ()
{
    return Interval(2, TERCIA_LARGE);
}


Interval Interval::CreateKvartaPure    ()
{
    return Interval(3, KVARTA_PURE);
}


Interval Interval::CreateKvartaEnlarged()
{
    return Interval(3, KVARTA_ENLARGED);
}


Interval Interval::CreateKvintaShrinked()
{
    return Interval(4, KVINTA_SHRINKED);
}

Interval Interval::CreateKvintaPure()
{
    return Interval(4, KVINTA_PURE);
}

Interval Interval::CreateSekstaSmall   ()
{
    return Interval(5, SEKSTA_SMALL);
}


Interval Interval::CreateSekstaLarge   ()
{
    return Interval(5, SEKSTA_LARGE);
}


Interval Interval::CreateSeptimaSmall  ()
{
    return Interval(6, SEPTIMA_SMALL);
}


Interval Interval::CreateSeptimaLarge  ()
{
    return Interval(6, SEPTIMA_LARGE);
}


Interval Interval::CreateOktavaPure    ()
{
    return Interval(7, OKTAVA_PURE);
}






//////////////////////////////////////////////////////////
//               GETTERS                                //
//////////////////////////////////////////////////////////
size_t Interval::GetNotesCount()     const
{
    return notesCount_;
}


size_t Interval::GetHalfTonesCount() const
{
    return halfTonesCount_;
}




