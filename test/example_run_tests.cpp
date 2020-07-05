#include "gtest/gtest.h"
#include "example.h"

#include <new>
#include <stdio.h>

#include <bits/stdc++.h>
using namespace std;
int tests_compile_execute()
{
  char filename[100];
  cout << "Enter file name to compile ";
  cin.getline(filename, 100);

  // Build command to execute.  For example if the input
  // file name is a.cpp, then str holds "gcc -o a.out a.cpp"
  // Here -o is used to specify executable file name
  string str = "gcc ";
  str = str + " -o a.out " + filename;

  // Convert string to const char * as system requires
  // parameter of type const char *
  const char *command = str.c_str();

  cout << "Compiling file using " << command << endl;
  system(command);

  cout << "\nRunning file ";
  system("./a.out");

  return 0;
}

int tests_run_hello()
{
  cout << "Hello World!" << endl;

  const char *command = "ls";
  cout << "cmd: " << command << endl;
  // system("tdd_t_maint_v8");
  system(command);
  return 0;
}

// run tdd script
int tests_run_tdd()
{
  int ret = 0;

  cout << "tests: " << endl;

  const char *command = "tdd_t_maint_v8 ";
  cout << "cmd: " << command << endl;
  ret = system(command);

  cout << "ret: " << ret << endl;
  return ret;
}

// test wled
// tdd/tools/tests/wled
int tests_run_tdd_wled()
{
  int ret = 0;

  cout << "tests: " << endl;

  const char *command = "cd ../tdd/tools/tests/wled;tdd_t_maint_v8 ";
  cout << "cmd: " << command << endl;
  ret = system(command);

  cout << "ret: " << ret << endl;
  return ret;
}

/**
 * test wled all
 * tdd/tools/tests/wled
 *
*/
// wled tests
std::string wled_tests[] = {
  "help",
  "t1s1_asku",
  "t1s1_finddev   ",
  "t1s1_ledpvoff  ",
  "t1s1_ledpvon   ",
  "t1s1_mcast     ",
  "t1s1_settime   ",
  "t1s1_synctime  "
};

// int tests_run_tdd_wled_all()
// {
//   int ret = 0;

//   const char *tst_help = " wled tests all ";
//   cout << tst_help << endl;

//   string tst_cmd = "cd ../tdd/tools/tests/wled; ";
//   tst_cmd = tst_cmd + "tdd_t_maint_v8 ";

//   // TODO: FIXME, to add tests from arrary or test config file
//   // Declaring vector of string type for tests
//   vector<string> tests;
//   // Initialize vector with string using push_back
//   int tests_num = sizeof(wled_tests);
//   cout << "tests_num: " << tests_num << endl;

//   for (int i = 0; i < 1; i++) {
//     tests.push_back(wled_tests[i]);
//   }

//   //
//   for (int i = 0; i < tests.size(); i++) {
//     // Convert string to const char * for system call
//     string start_cmd = tst_cmd;
//     start_cmd += tests[i].c_str();
//     const char *command = start_cmd.c_str();
//     cout << "cmd: " << command << endl;
//     ret = system(command);
//     cout << "ret: " << ret << endl;
//   }
//   return ret;
// }

// Read tests from files
int tests_run_tdd_wled_all()
{
  int ret = -1;

  const char *tst_help = " wled tests all ";
  cout << tst_help << endl;

  string tst_cmd = "cd ../tdd/tools/tests/wled; ";
  tst_cmd = tst_cmd + "tdd_t_maint_v8 ";

  // TODO: FIXME, to add tests from config file

  // Declaring vector of string type for tests

  ifstream input;
  string tests_file = "../tdd/tools/tests/wled/wled_tests.txt";
  system("pwd");
  input.open(tests_file);
  if (input.fail()) {    
    cout << "Error: no tests file existing!(" << tests_file << ")" << endl;
    // return ret;
  } else {
    vector<string> tests;
    string token;
    int tests_num = 0;

    // Initialize vector with string using push_back
    while (input >> token) {
    //   cout << " here is a test: " << token << endl;
      // Check comment or test, #
      char test_flag = token.at(0);
    //   cout << "test flag: " << test_flag << endl;
      if (test_flag == '#') {
          continue;
      }
      cout << " here is a test: " << token << endl;
      tests.push_back(token);
      tests_num++;
    }

    cout << "There are " << tests_num << " total tests." << endl;

    // run tests
    for (int i = 0; i < tests.size(); i++) {
      // Convert string to const char * for system call
      string start_cmd = tst_cmd;
      start_cmd += tests[i].c_str();
      const char *command = start_cmd.c_str();
      cout << "cmd: " << command << endl;
      ret = system(command);
      cout << "ret: " << ret << endl;
    }
  }
  return ret;
}

/*
 * =========== TESTS ===========
 */

TEST(example, tests_run_hello)
{
  int ret = 0;
  ret = tests_run_hello();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd)
{
  int ret = 0;
  ret = tests_run_tdd();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd_wled)
{
  int ret = 0;
  ret = tests_run_tdd_wled();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd_wled_all)
{
  int ret = 0;
  ret = tests_run_tdd_wled_all();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}
