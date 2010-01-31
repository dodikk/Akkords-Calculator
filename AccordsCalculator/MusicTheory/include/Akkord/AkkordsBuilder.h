#ifndef __AKKORDS_BUILDER_H__
#define __AKKORDS_BUILDER_H__

#include "NoteHeight/NoteHeight.h"

namespace LibMusic
{
    class AkkordsBuilder
    {
    private:
        AkkordsBuilder();
        ~AkkordsBuilder();

    public:
        static void BuildMajor(const NoteHeight& baseNote, Akkord& result);
        static void BuildMinor(const NoteHeight& baseNote, Akkord& result);
        static void BuildEnlarged(const NoteHeight& baseNote, Akkord& result);
        static void BuildShrinked(const NoteHeight& baseNote, Akkord& result);
    };
}


#endif //__AKKORDS_BUILDER_H__

