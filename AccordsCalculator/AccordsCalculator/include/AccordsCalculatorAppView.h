#ifndef ACCORDS_CALCULATOR_APP_VIEW_H_INCLUDED
#define ACCORDS_CALCULATOR_APP_VIEW_H_INCLUDED


#include <Wt/WApplication>

//containers
#include <Wt/WGroupBox>
#include <Wt/WTabWidget>
#include <Wt/WBorderLayout>
#include <Wt/WContainerWidget>

#include <Wt/WStringListModel>
#include <Wt/Ext/TableView>

#include <Wt/WTable>


//widgets
#include <Wt/WText>
#include <Wt/WLineEdit>
#include <Wt/WComboBox>
#include <Wt/WPushButton>
#include <Wt/WRadioButton>
#include <Wt/WButtonGroup>



namespace WebUi
{
    class AccordsCalculatorAppView : public Wt::WApplication
    {
    public:
        AccordsCalculatorAppView(const Wt::WEnvironment& env);


    private:
        void InitializeMainLayout();
        void InitializeMiddleArea();
        void InitializeWidgets();

    private:
        void InitializeLogo();
        void InitializeNotePicker();
        void InitializeAlterationSelector();
        void InitializeChordBuilderTabs();

    private:
        void InitializeSimpleChordsTab();
        void InitializeSeptChordsTab();

    private:
        void InitializeLaunchButton();
        void InitializeResultTable();



    protected:
        Wt::WBorderLayout*    layout_         ;
        Wt::WContainerWidget* mainContainer_  ;
        Wt::WText*            greeting_       ; 

    protected:
        Wt::WContainerWidget* middleContainer_;
        Wt::WGridLayout*      middleLayout_   ;

    protected:
        Wt::WPushButton* btnCalculate_;

    protected:
        Wt::WText*     lblNoteBase_;
        Wt::WComboBox* cbNoteBase_ ;


    protected:
        Wt::WGroupBox*    gbAlteration_   ;
        Wt::WRadioButton* rbNone_         ; 
        Wt::WRadioButton* rbDies_         ;
        Wt::WRadioButton* rbBemol_        ;
        Wt::WButtonGroup* alterationGroup_;


    protected:
        Wt::WTabWidget*       twChordsDescriber_ ;
        Wt::WContainerWidget* tabThreeSoundChord_;
        Wt::WContainerWidget* tabSeptAkkord_     ;

    protected:
        Wt::WGroupBox*    gbSimpleChords_;
        Wt::WRadioButton* rbMajor_   ; 
        Wt::WRadioButton* rbMinor_   ;
        Wt::WRadioButton* rbEnlarged_;
        Wt::WRadioButton* rbShrinked_;
        Wt::WButtonGroup* simpleChordsGroup_;

    protected:
        Wt::WGroupBox*    gbSeptChords_      ;
        Wt::WRadioButton* rbSmallMajorSept_  ; 
        Wt::WRadioButton* rbLargeMajorSept_  ; 
        Wt::WRadioButton* rbSmallMinorSept_  ;
        Wt::WRadioButton* rbLargeMinorSept_  ;
        Wt::WRadioButton* rbHalfShrinkedSept_;
        Wt::WRadioButton* rbShrinkedSept_    ;
        Wt::WRadioButton* rbEnlargedSept_    ;
        Wt::WButtonGroup* septChordsGroup_   ;
        Wt::WTable*       septChordsLayout_  ;


    protected:
        Wt::Ext::TableView*   resultTable_;
        Wt::WStringListModel* resultModel_;
    };

};


#endif // GREETAPP_H_INCLUDED
