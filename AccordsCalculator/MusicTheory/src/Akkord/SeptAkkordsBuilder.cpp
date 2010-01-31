#include "stdafx.h"
#include "SeptAkkordsBuilder.h"


using namespace LibMusic;


void SeptAkkordsBuilder::BuildSmallMajorSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildMajor(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_SMALL;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildBigMajorSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildMajor(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_LARGE;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildSmallMinorSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildMinor(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_SMALL;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildBigMinorSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildMinor(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_LARGE;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildHalfShrinkedSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildShrinked(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_LARGE;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildShrinkedSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildShrinked(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_SMALL;

    result.push_back(note);
}


void SeptAkkordsBuilder::BuildEnlargedSept(const NoteHeight& baseNote, Akkord& result)
{
    result.clear();
    AkkordsBuilder::BuildEnlarged(baseNote, result);

    const NoteHeight& last = result.back();
    NoteHeight note = last + TERCIA_SMALL;

    result.push_back(note);
}




