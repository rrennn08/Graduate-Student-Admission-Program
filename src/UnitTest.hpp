#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <string>
#include <iostream>
#include "student.hpp"
namespace UnitTest{

    void TestInsert(){
        //corner: right data type, wrong range
        //illegal case: wrong data type

        //test 1: insertion
        DomesticList test;
        cout <<"\nDomestic inserting Normal Case: first, last, 4.33, 100, 123456789, BC\n";
        test.sortedInsert("first", "last", "4.33", "100", 123456789, "BC");
        cout <<"\nDomestic inserting Corner Case: first, last, 5.33, 110, 123456789, FAKEPROVINCE\n";
        test.sortedInsert("first", "last", "5.33", "110", 123456789, "FAKEPROVINCE");
        cout <<"\nDomestic inserting Illegal Case: first, last, four, hundred, 123456789, 123\n";
        test.sortedInsert("first", "last", "four", "hundred", 123456789, "123");
        test.display();

        cout << "\nTOEFL: S:30, R:30, L:30, W:30" << endl;
        toefl toeflTest; //correct
        toeflTest.setSpeaking(30);
        toeflTest.setReading(30);
        toeflTest.setListening(30);
        toeflTest.setWriting(30);
        toeflTest.setTotal();

        cout << "TOEFL: S:1, R:1, L:1, W:1" << endl;
        toefl toeflWrong; //should be caught by error check
        toeflWrong.setSpeaking(1);
        toeflWrong.setReading(1);
        toeflWrong.setListening(1);
        toeflWrong.setWriting(1);
        toeflWrong.setTotal();

        InternationalList Test;
         cout <<"\nInternational inserting Normal Case: first, last, 4.33, 100, 123456789, China, toeflTest\n";
         Test.sortedInsert("first", "last", "4.33", "100", 123456789, "China", toeflTest);
         cout <<"\nInternational inserting Corner Case: first, last, 5.33, 110, 123456789, FAKECOUNTRY, toeflWrong\n";
         Test.sortedInsert("first", "last", "5.33", "110", 123456789, "FAKEPROVINCE", toeflWrong);
         cout <<"\nInternational inserting Illegal Case: first, last, four, hundred, 123456789, 123, toeflWrong\n";
         Test.sortedInsert("first", "last", "four", "hundred", 123456789, "123", toeflWrong);
         Test.display();


        //test 2: searchOne
        //dom cgpa
        cout << "Domestic searchOne Test: " << endl;
        cout << "Please insert normal case: CGPA -> 4.33" << endl; //found
        test.searchOne();
        cout << "Please insert corner case: CGPA -> 5.33" << endl; //not found
        test.searchOne();
        cout << "Please insert corner case: CGPA -> ABC" << endl; //invalid input
        test.searchOne();
        //dom research
        cout << "Please insert normal case: Research -> 100" << endl;
        test.searchOne();
        cout << "Please insert normal case: Research -> 101" << endl;
        test.searchOne();
        cout << "Please insert normal case: Research -> ABC" << endl;
        test.searchOne();
        //dom id
        cout << "PLease insert normal case: ID -> 123456789" << endl;
        test.searchOne();
        cout << "PLease insert normal case: ID -> 1" << endl;
        test.searchOne();
        cout << "PLease insert normal case: ID -> ABC" << endl;
        test.searchOne();

        //intl cgpa
        cout << "\nInternational searchOne Test: " << endl;
        cout << "Please insert normal case: CGPA -> 4.33" << endl; //found
        Test.searchOne();
        cout << "Please insert corner case: CGPA -> 5.33" << endl; //not found
        Test.searchOne();
        cout << "Please insert corner case: CGPA -> ABC" << endl; //invalid input
        Test.searchOne();
        //intl research
        cout << "Please insert normal case: Research -> 100" << endl;
        Test.searchOne();
        cout << "Please insert normal case: Research -> 101" << endl;
        Test.searchOne();
        cout << "Please insert normal case: Research -> ABC" << endl;
        Test.searchOne();
        //intl id
        cout << "PLease insert normal case: ID -> 123456789" << endl;
        Test.searchOne();
        cout << "PLease insert normal case: ID -> 1" << endl;
        Test.searchOne();
        cout << "PLease insert normal case: ID -> ABC" << endl;
        Test.searchOne();

        //test 3: searchTwo
        //dom
        cout << "\nDomestic searchTwo test" << endl;
        cout << "Please insert: First: first, Last: last" << endl; //normal
        test.searchTwo();
        cout << "Please insert: First: non, Last: existent" << endl; //corner
        test.searchTwo();
        cout << "Please insert: First: 123, Last: 123" << endl; //illegal
        test.searchTwo();
        //intl
        cout << "\nInternational searchTwo test" << endl;
        cout << "Please insert: First: first, Last: last" << endl; //normal
        Test.searchTwo();
        cout << "Please insert: First: non, Last: existent" << endl; //corner
        Test.searchTwo();
        cout << "PLease insert: First: 123, Last: 123" << endl; //illegal
        Test.searchTwo();

        //test4: selectDelete

        //test 5: deleteHeadTail
        test.deleteHeadTail();
        test.display();
        Test.deleteHeadTail();
        Test.display();

        //test 6: merge
        MergeList testerino;
        testerino.sortedMerge(test, Test);

        //test 7: mergeSearch
        testerino.search("4.33", "100"); //normal
        testerino.search("5.33", "101"); //corner
        testerino.search("ABC", "ABC"); //illegal

    }

};

#endif
