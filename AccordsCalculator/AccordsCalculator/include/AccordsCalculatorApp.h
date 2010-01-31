#ifndef ACCORDS_CALCULATOR_APP_H_INCLUDED
#define ACCORDS_CALCULATOR_APP_H_INCLUDED

#include "AccordsCalculatorAppView.h"


#include "NoteHeight/NoteHeightValues.h"
#include "NoteHeight/AlterationSign.h"
#include "NoteHeight/NoteHeight.h"

#include <boost/function.hpp>

namespace WebUi
{
    class AccordsCalculatorApp : public AccordsCalculatorAppView
    {
    public:
        typedef AccordsCalculatorAppView ParentClass;
        typedef boost::function<void (const LibMusic::NoteHeight&, LibMusic::Akkord&)> AkkordBuildCallback;

    public:
        AccordsCalculatorApp(const Wt::WEnvironment& env);

    private:
        void SetupEvents();
        void SetupWidgets();

    private:
        void InitializeNotesComboBox();

    private: // event handlers
        void OnCbNoteBase_valueChanged(int index);
        void OnBtnCalculate_pressed();

    private:
        AkkordBuildCallback GetBuildCallback() const;
        AkkordBuildCallback GetSimpleBuildCallback() const;
        AkkordBuildCallback GetSeptBuildCallback() const;

    private:
        const LibMusic::NoteHeight& BuildBaseNote() const;
        LibMusic::AlterationSign GetAlterationSign() const;
        
    private:
        LibMusic::NoteHeight ApplyAlteration(const LibMusic::NoteHeight& note, LibMusic::AlterationSign alt) const;
        
    private:
        void DoBuildAkkord(LibMusic::Akkord& result) const;
        void DrawAkkord(const LibMusic::Akkord& akkord);


    private: // utilities
        static const LibMusic::RawNoteHeight notes_[];
        static const int eIndex_;
        static const int fIndex_;
        static const int hIndex_;
        static const int cIndex_;
    };
}

#endif 
