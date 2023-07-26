#include "pch.h"
#include "CppUnitTest.h"
#include "Test_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(T001)
        {
            const int loc1[2] = { 3, 4 };
            const int loc2[2] = { 3, 4 };
            double minDest = 5.0;
            double result = returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(0.0, result);
        }
        TEST_METHOD(T002)
        {
            const int loc1[2] = { 2, 4 };
            const int loc2[2] = { 8, 4 };
            double minDest = 5.0;
            double result= returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(6.0, result);
        }
        TEST_METHOD(T003)
        {
            const int loc1[2] = { 5, 3 };
            const int loc2[2] = { 5, 9 };
            double minDest = 8.0;
            double result = returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(6.0, result);
        }
        TEST_METHOD(T004)
        {
            const int loc1[2] = { 2, 2 };
            const int loc2[2] = { 5, 6 };
            double minDest = 10.0;
            double result = returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(5.0, result);
        }
        TEST_METHOD(T005)
        {
            const int loc1[2] = { -2,-2 };
            const int loc2[2] = { -5, -6 };
            double minDest = 10.0;
            double result = returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(5.0, result);
        }

        TEST_METHOD(T006)
        {
            const int* loc1 = nullptr;
            const int loc2[2] = { -5, -6 };
            double minDest = 5.0;
            double result = returnDistance(loc1, loc2, &minDest);
            Assert::AreEqual(-1.0, result);
        }

        TEST_METHOD(T007)
        {
            const int loc1[] = { 0, 0 };
            const int loc2[] = { 10, 10 };
            double* minDest = nullptr;
            double result = returnDistance(loc1, loc2, minDest);
            Assert::AreEqual(-1.0, result);
        }

        //Valid: weight < weightLeft and volumLeft > 0
        TEST_METHOD(T008)
        {
            // input
            double weight = 500.0;
            int volumeLeft = 10;
            double weightLeft = 800.0;
           
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(1, result);
        }

        //Invalid: weight > weightLeft but volumeLedt > 0
        TEST_METHOD(T009)
        {
            // input
            double weight = 1200.0;
            int volumeLeft = 10;
            double weightLeft = 800.0;

            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        //Invalid: weight < weightLeft but volumeLeft = 0
        TEST_METHOD(T010)
        {
            // input
            double weight = 500.0;
            int volumeLeft = 0;
            double weightLeft = 800.0;

            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        //Invalid weight > weightLeft and volumeLeft = 0
        TEST_METHOD(T011)
        {
            // input
            double weight = 1200.0;
            int volumeLeft = 0;
            double weightLeft = 800.0;

            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        //Valid: weight = weightLeft and volumLeft > 0
        TEST_METHOD(T012)
        {
            // input
            double weight = 800.0;
            int volumeLeft = 1;
            double weightLeft = 800.0;

            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(1, result);
        }

        //Valid size
        TEST_METHOD(T013) {
            int result = checkSize(QUARTER_SIZE);
            Assert::AreEqual(1, result);
        }

        //Invalid size
        TEST_METHOD(T014) {
            int result = checkSize(0.75);
            Assert::AreEqual(0, result);
        }

        //Valid size
        TEST_METHOD(T015) {
            int result = checkSize(FULL_SIZE);
            Assert::AreEqual(1, result);
        }

        //Valid size
        TEST_METHOD(T016) {
            int result = checkSize(HALF_SIZE);
            Assert::AreEqual(1, result);
        }

        //Invalid size
        TEST_METHOD(T017) {
            int result = checkSize(-0.25);
            Assert::AreEqual(0, result);
        }
       
        //Invalid size
        TEST_METHOD(T018) {
            int result = checkSize(-1.0);
            Assert::AreEqual(0, result);
        }

        /**/
        //Valid both column and row
        TEST_METHOD(T019) {
            int result = validDestination(10, "D"); // Use a string literal for single characters
            Assert::AreEqual(1, result);
        }

        //Invalid row
        TEST_METHOD(T020) {
            int result = validDestination(30, "F"); // Use a string literal for single characters
            Assert::AreEqual(0, result);
        }

        //Invalid column
        TEST_METHOD(T021) {
            int result = validDestination(15, "Z"); // Use a string literal for single characters
            Assert::AreEqual(0, result);
        }

        //Invalid column
        TEST_METHOD(T022) {
            int result = validDestination(15, "@"); // Use a string literal for single characters
            Assert::AreEqual(0, result);
        }

        //Invalid column
        TEST_METHOD(T023) {
            int result = validDestination(1, ""); // Use an empty string for NULL
            Assert::AreEqual(0, result);
        }

        //Valid column : in lowercase
        TEST_METHOD(T024) {
            int result = validDestination(1, "a"); // Use a string literal for single characters
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(T025) {
            int result = validDestination(1, NULL); // Use nullptr or NULL
            Assert::AreEqual(0, result);
        }

        //Invalid row
        TEST_METHOD(T026) {
            int result = validDestination(1, "AB"); // Use a string literal for single characters
            Assert::AreEqual(0, result);
        }












































        /*
      //Valid both column and row
      TEST_METHOD(T019) {
          int result = validDestination(10, 'D');
          Assert::AreEqual(1, result);
      }

      //Invalid row
      TEST_METHOD(T020) {
          int result = validDestination(30, 'F');
          Assert::AreEqual(0, result);
      }

      //Invalid column
      TEST_METHOD(T021) {
          int result = validDestination(15, 'Z');
          Assert::AreEqual(0, result);
      }

      //Invalid column
      TEST_METHOD(T022) {
          int result = validDestination(15, '@');
          Assert::AreEqual(0, result);
      }

      //Invalid column
      TEST_METHOD(T023) {
          int result = validDestination(1, '\0');
          Assert::AreEqual(0, result);
      }

      //Valid column : in lowercase
      TEST_METHOD(T024) {
          int result = validDestination(1, 'a');
          Assert::AreEqual(1, result);
      }

      TEST_METHOD(T025) {
          int result = validDestination(1, NULL);
          Assert::AreEqual(0, result);
      }

      //Invalid row
      TEST_METHOD(T026) {
          int result = validDestination(1, 'AB');
          Assert::AreEqual(0, result);
      }*/

	};
}
