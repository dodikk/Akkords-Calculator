#include "stdafx.h"
#include "AkkordsBuilder.h"

using namespace LibMusic;


void AkkordsBuilder::BuildMajor(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    
    NoteHeight note2 = baseNote + TERCIA_LARGE;
    NoteHeight note3 = note2    + TERCIA_SMALL;

    result.push_back(baseNote);
    result.push_back(note2   );
    result.push_back(note3   );
}


void AkkordsBuilder::BuildMinor(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();

    NoteHeight note2 = baseNote + TERCIA_SMALL;
    NoteHeight note3 = note2    + TERCIA_LARGE;

    result.push_back(baseNote);
    result.push_back(note2   );
    result.push_back(note3   );
}


void AkkordsBuilder::BuildEnlarged(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();

    NoteHeight note2 = baseNote + TERCIA_LARGE;
    NoteHeight note3 = note2    + TERCIA_LARGE;

    result.push_back(baseNote);
    result.push_back(note2   );
    result.push_back(note3   );
}


void AkkordsBuilder::BuildShrinked(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();

    NoteHeight note2 = baseNote + TERCIA_SMALL;
    NoteHeight note3 = note2    + TERCIA_SMALL;

    result.push_back(baseNote);
    result.push_back(note2   );
    result.push_back(note3   );
}




