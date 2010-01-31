#ifndef __NOTE_HEIGHT_VALUES_H__
#define __NOTE_HEIGHT_VALUES_H__

#include "MusicTypes.h"

namespace LibMusic
{
    class NoteHeightValues
    {
    private:
        NoteHeightValues();
        ~NoteHeightValues();

    public:
        static const RawNoteHeight c;
        static const RawNoteHeight d;
        static const RawNoteHeight e;
        static const RawNoteHeight f;
        static const RawNoteHeight g;
        static const RawNoteHeight a;
        static const RawNoteHeight h;


        static const RawNoteHeight c_dies;
        static const RawNoteHeight d_dies;
        static const RawNoteHeight f_dies;
        static const RawNoteHeight g_dies;
        static const RawNoteHeight a_dies;


        static const RawNoteHeight d_bemol;
        static const RawNoteHeight e_bemol;
        static const RawNoteHeight g_bemol;
        static const RawNoteHeight a_bemol;
        static const RawNoteHeight h_bemol;
    };
}


#endif

