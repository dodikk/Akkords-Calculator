#ifndef __NOTE_HEIGHT_H__
#define __NOTE_HEIGHT_H__

#include "MusicTypes.h"
#include <vector>

namespace LibMusic
{
    class NoteHeight
    {
    private:
        explicit NoteHeight(RawNoteHeight value = 0, bool isAscending = false);

    public:
        static NoteHeight CreateC();
        static NoteHeight CreateD();
        static NoteHeight CreateE();
        static NoteHeight CreateF();
        static NoteHeight CreateG();
        static NoteHeight CreateA();
        static NoteHeight CreateH();
        
        static NoteHeight CreateC_dies();
        static NoteHeight CreateD_dies();
        static NoteHeight CreateF_dies();
        static NoteHeight CreateG_dies();
        static NoteHeight CreateA_dies();

        static NoteHeight CreateD_bemol();
        static NoteHeight CreateE_bemol();
        static NoteHeight CreateG_bemol();
        static NoteHeight CreateA_bemol();
        static NoteHeight CreateH_bemol();


    public:
        RawNoteHeight GetRawHeight() const;
        bool IsAscending() const;
        const std::wstring& GetNoteName() const;

    public: // operators
        NoteHeight& operator+=(RawNoteHeight diff);
        NoteHeight& operator-=(RawNoteHeight diff);

        NoteHeight& operator++();    //prefix
        NoteHeight operator++(int); //postfix

        NoteHeight& operator--();    //prefix
        NoteHeight operator--(int); //postfix



    private:
        void InitializeHeaders();
        void InitializeAscendingHeaders();
        void InitializeDescendingHeaders();

    private:
        RawNoteHeight NormalizeValue(RawNoteHeight value) const;
        
    private:
        static wstring_vt ascendingNames_ ;
        static wstring_vt descendingNames_;

    private:
        RawNoteHeight value_;
        bool isAscending_;
    };

    typedef std::vector<NoteHeight> NoteHeight_vt;
    typedef NoteHeight_vt Akkord;

    NoteHeight operator+(const NoteHeight& left, RawNoteHeight right);
    NoteHeight operator-(const NoteHeight& left, RawNoteHeight right);

    NoteHeightDistance operator-(const NoteHeight& left, const NoteHeight& right);
}


#endif 

