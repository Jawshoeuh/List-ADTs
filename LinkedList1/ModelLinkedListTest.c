#include <stdint.h>
#include <stdio.h>
#include <setjmp.h>

//Types of exceptions to throw.

#include "LinkedList.h"

#define FIRST_TEST Append_Test

enum LL_TESTS {
  //Element Adding Tests
  Append_Test = 0,
  InsertAfter_Test,
  //Element Removing Tests
  DeleteAfter_Test,
  //Element Modification Tests
  Replace_Test,
  //Accessor Tets
  FindNth_Test,
  Length_Test,
  Get_Test,
  //Number of Tests
  NUM_TESTS,
};

char *testToString(int test) {
  switch(test) {
    case Append_Test:      return "Append_Test";
    case InsertAfter_Test: return "InsertAfter_Test";
    case DeleteAfter_Test: return "DeleteAfter_Test";
    case Replace_Test:     return "Replace_Test";
    case FindNth_Test:     return "FindNth_Test";
    case Length_Test:      return "Length_Test";
    case Get_Test:         return "Get_Test";
    default:               return "Error, Test Out of Bounds";
  }
}

uint8_t runTest(LinkedList *LL1, LinkedList *LL2, LinkedList *LL3, int test) {
  switch(test) {
    case Append_Test:
    case InsertAfter_Test:
    case DeleteAfter_Test:
    case Replace_Test:
    case FindNth_Test:
    case Length_Test:
    case Get_Test:
    default:
      return 0;
  }
}

int main (int argc, char **argv) {
  //Handle arguments.
  for(uint8_t i = FIRST_TEST; i < NUM_TESTS; i++) {
    
  }
}