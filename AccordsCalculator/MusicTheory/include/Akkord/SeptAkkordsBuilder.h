#ifndef SeptAkkordsBuilder_h__
#define SeptAkkordsBuilder_h__

#include "NoteHeight/NoteHeight.h"

namespace LibMusic
{
    class SeptAkkordsBuilder
    {
    private:
        SeptAkkordsBuilder();
        ~SeptAkkordsBuilder();

    public:
        static void BuildSmallMajorSept  (const NoteHeight& baseNote, Akkord& result);
        static void BuildBigMajorSept    (const NoteHeight& baseNote, Akkord& result);
        static void BuildSmallMinorSept  (const NoteHeight& baseNote, Akkord& result);
        static void BuildBigMinorSept    (const NoteHeight& baseNote, Akkord& result);
        static void BuildHalfShrinkedSept(const NoteHeight& baseNote, Akkord& result);
        static void BuildShrinkedSept    (const NoteHeight& baseNote, Akkord& result);
        static void BuildEnlargedSept    (const NoteHeight& baseNote, Akkord& result);
    };
}

#endif // SeptAkkordsBuilder_h__
